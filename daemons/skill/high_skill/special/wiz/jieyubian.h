// jieyubian.h ���Z�޷�
//code by Teapot
//date : 2001-04-23

SKILL_BEGIN(CSjieyu_bian);

virtual void create()
{
	set_name( "���Z�޷�");

	Magic_t * magic;

	magic = add_magic("rain", do_rain);
	magic->name = "�y�t�w�^��ǧȥ";
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
		{"$Nʹһ�С��Ȼ����Z����$w�p�p�d�d�Ķ���$n��", 0, -10, 0, "����",},
		{"$N���է����һ�С�������ˮ����$w��ͬ�o߅���ᣬ��$n��ȥ��", 0, -15, 20, "����",},
		{"$N�v���𣬜R��̤̓����$n��߅���^����Ц�л���һ�ޣ����ǡ����R��÷����", 0, -20, 40, "����",},
		{"$N�p�pһ�@������һ����һʽ����С�o�¡�ֱȡ$n��", 0, -35, 60, "����",},
		{"$N����Ϊ����һʽ���麣���ġ��d�d���ܵĹ�����", 0,-40 , 80, "����",},
		{"$N���һ���D���p�]$w����һ�С�����ĺĺ����", 0,-50 , 100, "����",},
	 	{"$Nʹ�����������á���һ��$w��$n���ɼ���ײ��$w��", 0, -60, 120, "����",},
		{"$Nʹ�����������Ρ������b�X�Ú��֮�ϣ���Ҋ���컨�꣬�o�����ڡ��o���������o��������w��������", 600, -80, 150, "����",},
	};

	int level = me->query_skill("jieyu_bian", 1);
	
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


	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "whip");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("�W���Z�޷�����ğo�s�");
	if(me->querymap("couple")) 
		return notify_fail("�W���Z�޷�����ğo�s�");
//    if (DIFFERSTR(me->querystr("gender"), "Ů��")  )
//		return notify_fail("�W���Z�޷�����ğo�s�");
    if ( me->query("max_mp") < 5000)
		return notify_fail("�������̫�����޷������Z�޷���");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("mp") > 0)
		return notify_fail("����������򾚽��Z�޷���");
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
		return notify_fail("�y�t�w�^��ǧȥֻ�܌����Y�еČ���ʹ�á�");
	
	if(  me->query_skill("jieyu_bian", 1) < 20+me->query("level")*4 )
		return notify_fail("��Ľ��Z�޷��ȼ����㣬����ʹ�����y�t�w�^��ǧȥ����");

	if( me->query("mp") < 1000)	
		return notify_fail("����������㡣");
	me->add("mp",-1000);	


	message_vision("$HIG$N�D���p̤������һ���S�֠�����ֻҊ���컨Ӱ�������P�P�Ğ���$n����",me,target);

	if(random(me->query("max_mp"))> random(target->query("mp") +  target->query_skill("dodge") * 10 + 1)) 
	{
		message_vision("$HIY$n���������֮�У������f��Ȼ���У�",me,target);
		target->receive_damage("hp", (2*random(me->query("max_mp")/2)+1) );
	}
	else
	{
		message_vision("$HIG$n����һʎ�������Ļ��^���꣬��������ϣ������ġ��y�t�w�^��ǧȥ����",me,target);
		me->start_busy(4);
	}

	return 1;
}

SKILL_END;


