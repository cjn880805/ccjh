// fengyu_wuqingzhi.h �L��o��ָ
//code by Teapot
//date : 2001-04-20

SKILL_BEGIN(CSfengyu_wuqingzhi);

virtual void create()
{
	set_name( "�L��o��ָ");

	Magic_t * magic;

	magic = add_magic("rain", do_rain);
	magic->name = "�L�����";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;


}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С�����է�𡹣�һָ��֪������֪��ȥ�Ĺ�����", 100, 10, 0, "����",},
		{"$N���է����һ�С�ϸ�����ࡹ��ָ�L�o�ײ���Ĺ���$n��", 150, 15, 20, "����",},
		{"$N�v���𣬜R��̤̓���bҊ����ָӰ���£����ǡ����L�E�꡹��", 200, 20, 40, "����",},
		{"$N�p�pһ�@����ָ�B����һʽ���L�����ǡ�ֱȡ$n��", 250, 35, 60, "����",},
		{"$N��ָΪ����һʽ�����L������ᄦ���d�d���ܵĹ�����", 300,30 , 80, "����",},
		{"$N���һ���D���p��һָ����һ�С������P �L���꡹��", 350,35 , 100, "����",},
	 	{"$Nʹ���L��o��ָ�еġ���Թ�L�꿂�o߅����ʮָ�B�d���^��������ȫ��$n������ָ�L֮�£�", 400, 20, 120, "����",},
		{"$Nʹ�������L���꿂�o�项�����b�X�Ú��֮�ϣ���Ҋ�����L�꣬�o�����ڡ��o���������o��������w��������", 700, -80, 150, "����",},
	};

	int level = me->query_skill("fengyu_wuqingzhi", 1);
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}

	if (me->query_temp("teapot/perform_fengyuruhui"))
	{
			me->delete_temp("teapot/perform_fengyuruhui");
			m_actions.set("action", "$N���Ĕ��⣬�L��o��ָ�^�W�EȻ�l��!\nֻҊ���ꎳ������Lŭ��������ע���D˲�wס���������磬ͻȻ�@��է��һָ����u��$n����һ�С��L����ޡ�������");
			m_actions.set("force", 1200);
			m_actions.set("damage", 0l);
	}

	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("�W�L��o��ָ��횿��֡�");

    if (DIFFERSTR(me->querystr("gender"), "Ů��")  )
		return notify_fail("�W�L��o��ָ���Ů�ԡ�");

    if ( me->query("max_mp") > 1000)
		return notify_fail("�������̫ǿ���޷����L��o��ָ��");

    return 1;
	
}

int practice_skill(CChar * me)
{
    if ( me->query("mp") > 0)
		return notify_fail("�������̫ǿ���ܾ��L��o��ָ��");

    me->add("mp", 1);
	return 1;
	
}


//perform 
static int do_rain(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("�L�����ֻ�܌����Y�еČ���ʹ�á�");
	
	if(  me->query_skill("fengyu_wuqingzhi", 1) < 160 )
		return notify_fail("����L��o��ָ�ȼ����㣬����ʹ�����L����ޡ���");

	if( me->query("mp") < 1000)	
		return notify_fail("����������㡣");
	me->add("mp",-1000);	
	me->set_temp("teapot/perform_fengyuruhui",1);
	g_Combatd.Do_Attack(me,target, g_Combatd.TYPE_REGULAR);
	me->start_busy(3);
	return 1;
}



SKILL_END;


