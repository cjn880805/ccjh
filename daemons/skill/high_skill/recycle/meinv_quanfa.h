
// meinv_quanfa.h ��Ůȭ��
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSmeinv_quanfa);

virtual void create()
{
	set_name( "��Ůȭ��");

	Magic_t * magic;

	magic = add_magic("duo", do_duo);
	magic->name = "���������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("lianquan", do_lianquan);
	magic->name = "��ȭ";
	magic->mp = 100;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһ�� ������� ����ȭ���϶��»���$n��$l.", 5, 1,1, 0, "����",},
		{"$Nһʽ ���ҹ�� �����䲻��ߵ��ֱ�룬��׼$n��$l�ͻ����¡�", 15, 2,1,10 , "����",},
		{"$N������£�һʽ ����׹¥ ��ֱ��$n$l.",20 ,3 , 1,20, "����",},
		{"$N˫�Ʒ׷�,һ�� �ļ��麺 �����಻�ϵ�����$n", 25,4 , 1,30, "����",},
		{"$NͻȻ��ǰһ����һ�� ���ߵ��� ������$n��������������Ѩ", 30,5 , 1,40, "����",},
		{"$Nһʽ ľ���乭 �����ּܿ�$n�Ĺ��ƣ�������������$n��$l.", 35, 6, 1,50, "����",},
		{"$N˫Ŀ΢΢�Ϸ���˫��������һʽ �༧��ʫ ��˫�����Ҽй�������$n��$l",40 , 7,1,60 , "����",},
		{"$N��Ц��Ц,˫ȭ�����޶�,һʽ �϶���ҩ ,����ת����$nȫ����ʮ����Ѩ��", 45, 8, 1,70, "����",},
		{"$N�ڶ���֫��һʽ �������� ,�۽�$n����߽��ƹ���$n��$l", 50, 9, 1,80, "����",},
		{"$Nһʽ ������װ ,�ֱ��������¶��һ˿΢Ц��һ��������ǰ˫�ƽ����Ļ������ƻ���$n��$l", 55,10 , 1,90, "����",},
		{"$N�ҽ���ǰ�벽������һʽ �������� ,�ֱ����ͻȻһȭ����$n��$l", 60, 11, 1,100, "����",},
	};
	
	int level = 0;
	
	for(int i=11; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("meinv_quanfa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", me->query_skill("dodge")/4);
			m_actions.set("damage", me->query_skill("meinv_quanfa",1) * action[level].damage);
			m_actions.set("force", me->query("per") * action[level].force);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if(EQUALSTR(me->querystr("gender"), "����"))
		return notify_fail("��һ������үô��ѧ����");
	if (me->query_weapon())
		return notify_fail("����Ůȭ��������֡�");
	if (me->query_skill("yunv_xinjing", 1) < 10)
		return notify_fail("�����Ů�ľ���򲻹����޷�ѧ��Ůȭ��");
	if (me->query("max_mp") < 50)
		return notify_fail("�������̫�����޷�����Ůȭ��");
	return 1;
}

//perform 
static int do_duo(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	int skill;
	CContainer * weapon;
	string msg;
	
	if(ob &&ob->is_character())
		target = (CChar *) ob;

	if( me->query_temp("duo") )
		return notify_fail("���Ѿ��ڶ���˵ı����ˡ�");

	skill = me->query_skill("meinv_quanfa",1);
	
	if(!target || ! me->is_fighting(target))
		return notify_fail("���������ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if ( me->query_weapon())
		return notify_fail("�������֡�");
	
	if (!(weapon = target->query_weapon()))
		return notify_fail("�Է�û�б��У��㲻�õ��ġ�");
	
	if( skill < 50)
		return notify_fail("�����Ůȭ���ȼ�����, ���ܿ�������У�");
	
	if( me->query_skill("yunv_xinfa",1)<30)
		return notify_fail("�����Ů�ķ���Ϊ���㣬����ʩչ��������еĹ���");
	
	if( me->query("mp") < 100 )
		return notify_fail("��������������޷���������У�");
	
	msg =  "$N�����Ϣ������ʩչ��������еľ���.\n";
	me->add("mp",-100);

	if( me->query_skill("unarmed")+me->query_skill("unarmed")/2>target->query_skill("parry"))
	{
		msg += "$Nʹ����������еľ���, $n��ʱ������ǰһ��������һ�飬���б������ֶ�����" ;
		target->start_busy(2);
		weapon->move(me);
		me->start_busy(2);
	}
	else
	{
		msg += "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$Nû�ܶ��±��С�";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	
	return 1;
	
}

static int do_lianquan(CChar * me, CContainer * ob)
{
	int skill, jing_cost;
	string msg;
	skill = me->query_skill("meinv_quanfa",1);
	jing_cost = me->query("int") - 45;
	
	if (DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��"))  
		return notify_fail("�㲻�ǹ�Ĺ�ɵ��ӣ�����ʹ���ܾ�ʽ��ȭ����");
	
	if( me->is_fighting() )
		return notify_fail("���ܾ�ʽ��������ս����������");
	
	if (me->query_weapon())
		return notify_fail("����Ůȭ��������֡�");
	
	if (me->query_skill("tianluo_diwang",1)<30)
		return notify_fail("������޵����ƻ�򲻹����������ܾ�ʽ��ȭ��.");
	
	if( !skill || (skill < 20))
		return notify_fail("�����Ůȭ�����ȼ�����, �������ܾ�ʽ����");
	
	if( me->query("mp") < 100 )
		return notify_fail("�������������û����������Ůȭ��");
	
	if( me->query("hp") < -jing_cost )
		return notify_fail("������̫���ˣ��޷����о���������Ůȭ����");
	if(me->query_skill("yunv_xinfa",1)<me->query_skill("meinv_quanfa",1))
		return notify_fail("�����Ů�ķ���Ϊ����������Ůȭ���ˡ�");	
	
	msg =  "$N������һ����Ůȭ����\n";
		
	me->add("mp", -20);
	me->add("hp", - jing_cost);
	me->improve_skill("meinv_quanfa", (me->query_skill("meinv_quanfa",1)+(me->query_skill("meinv_quanfa",1)/2)));
	
	msg += "$P�ġ���Ůȭ���������ˣ�";
	me->start_busy(random(2));
	message_channel("practice", msg.c_str(), me);
	return 1;
}

SKILL_END;
