
// jinshe_zhui.h ����׶��
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSjinshe_zhui);

virtual void create()
{
	set_name( "����׶��");
	
	Magic_t * magic;
	
	magic = add_magic("tuwu", do_tuwu);
	magic->name = "��������";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)		//2001-07-23	sound����һ�ι�����
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,force,damage;
		char damage_type[5];
	}action[] = {
		{"$N˫��һ�Σ�һ�С�ǧ���򻯡������е�$w�ó������⣬��һ�����������$n��$l", -20, 200, 250, "����",},
		{"$N����һ����һ�����ð����ֻһɲ�Ǽ䣬����$wѸ�װ�Խ�����ֵ�$w������һ�С����Ī�⡹�����ȷ���$n��$l", -40, 200, 300, "����",},
	};
	
	int	level = random(2);
	m_actions.set("action", action[level].action);
	m_actions.set("damage", action[level].damage);
	m_actions.set("force", action[level].force);
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "throwing")  ;
}

virtual int valid_learn(CChar * me)
{
	if(me->query_skill("jinshe_zhui", 1) < 200)
		return notify_fail("�����Ϊ̫ǳ,�޷�������а���!");

	CContainer * ob;
	
	if(  me->query("max_mp") < 500 )
		return notify_fail("�������������û�а취������׶����");
	
	if( !(ob = me->query_weapon())
        ||       DIFFERSTR(ob->querystr("skill_type"), "throwing") )
		return notify_fail("���������һЩ��������������׶����");
	
	return notify_fail("����׶��û�����ڡ�");
}

virtual int practice_skill(CChar * me)
{
	if(me->query_skill("jinshe_zhui", 1) < 200)
		return notify_fail("�����Ϊ̫ǳ,�޷�������а���!");

	if(  me->query("hp") < 30
        ||       me->query("mp") < 500 )
		return 	notify_fail("�����������������û�а취��ϰ����׶����");
	me->receive_damage("hp", 30);
	me->add("mp", -30);
	tell_object(me,"�㰴����ѧ����һ�����׶����", "practice");
	return 1;
}

//perform 
static int do_tuwu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	int skill;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if (me->query_temp("jinshe/tuwu"))
		return notify_fail("����õĽ�������û�����žͳ��С�");
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ����ս����ʹ�á�");
	
    if (! (weapon = me->query_weapon())
        ||  DIFFERSTR(weapon->querystr("id"), "jinshe_zhui"))
		return notify_fail("��û�ý���׶������ʹ�þ��У�");
	
	if(  me->query_skill("jinshe_zhui", 1) < 100 )
		return notify_fail("��Ľ���׶��������죬����ʹ�ý�������");
	
	if(  me->query("mp") < 300 )
		return notify_fail("�����������ˡ�");
	
	skill = me->query_skill("jinshe_zhui", 1);
	
	me->add("mp", -200);
	target->receive_damage("hp",  skill/ 3);
	
	message_vision(	"ֻ��һ����ɨҶ��������У�$N���еĽ���׶������Ŀ�Ĺ�â����ҫ��$n��ð�𻨣�������������������ǰһ���ص������⣬$nɶҲ�������ˣ�"  , me, target);
	me->set_temp("jinshe/tuwu", 1);
	target->set_temp("block_msg/all",1);
	me->call_out(tuwu_end, skill/30, target->object_id() );
	
//	call_out("tuwu_end",   skill/30, me, target);
	
	return 1;
}

static void tuwu_end(CContainer * ob, LONG nTarget, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(nTarget);
	
	if(! target) return;
	
	target->enable_player();
	message_vision("$NĨ��Ĩ��������Ѫ�������������ۡ�", target);
	target->set_temp("block_msg/all", 0l);
	tell_object( me,"������Ĩ������������Ѫ����������Χ���龰��" );
	me->delete_temp("jinshe/tuwu");
	return;
}

SKILL_END;
