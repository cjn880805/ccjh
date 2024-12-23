// lovesword.h ���
// Coded by Teapot
// Create @ 2001-02-20
// Last Modify @ 2001-03-10


SKILL_BEGIN(CSloveblade);

virtual void create()
{
	set_name( "���");

/*	Magic_t * magic;

	magic = add_magic("crazy", do_crazy);
	magic->name = "����ն";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("suicidal", do_suicidal);
	magic->name = "����";
	magic->mp = 0;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("suicidalb", do_suicidalb);
	magic->name = "����";
	magic->mp = 0;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[4] = {
		{"$n��ͷ��$N���ĵĵ����ѵ������㵽���ڻ��������ҵ����⣿", -3000,-100,-100,-3000,0,},
		{"$n������������$N,���������㡭�����ڻ����ˡ���", -3000,-100,-100,-3000,0,},
		{"$n�ߺ�������$N˵����Ҫ���˵����㲻˵�˼���ô֪����Ҫ����", -3000,-100,-100,-3000,0,},
		{"$n��$N��������һȥ��ֻ�´Ӵ˲��������ֻ�����������Ժ��ܹ�����һ�𡭡� ", -3000,-100,-100,-3000,0,},
	};
	int level;
	level=random(4);
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);

	return & m_actions;
};

const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[6][255] ={
		"$n����ͻȻ���ֳ�һƬ����������$N���������֡�",
		"$n��ͷ��̾һ�����������ܣ�$Nһ㶣�ĬĬͣ�֡�",
		"$n������$N���е�ȥ��$Nֻ��ͣ�����ӡ�",
		"$n�����ã��ã��㡭�����۸��ң���˵������Ȧ�Ѿ����ˣ�$Nһ㶣�ͣ�ֲ�����",
		"$n����������һҹ���ް��ն�����ҹ���޺������$N��������һ���˸У�����ͣ����ʽ��",
		"$nʲôҲ��˵�������峺��ˮ��Ŀ�⿴��$N��$N����ǧ�ذ�ת������$n��ȥ�ĺ�����",
	};

	return parry_msg[random(6)];
}

virtual int valid_enable(string usage) { return usage=="blade" || usage == "parry" ; }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return 0;
}

/*
static int do_crazy(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("����նֻ�ܶ�ս���еĶ���ʹ�á�");

	if( !target->Query(IS_LIVING))
		return notify_fail("����û�б�Ҫʹ������ն������Ҳ��������");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("��������æ���ء�");

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");	// frost blade cast only.


	if( me->query("mp") < 500)	
		return notify_fail("�������������ʹ������ն��");

	int i;
	i=me->query("mp")/2;
	me->add("mp",-i);
	
	message_vision("$N΢΢һЦ��ͻȻ�佫���н���Ȼ�ӳ������д�������֮������ʱ$n����˷���������������Ҳ���������ݺ��ǳ����",me,target);

	return 1;
}

static int do_suicidal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�");

	if( !target->Query(IS_LIVING))
		return notify_fail("����û�б�Ҫʹ�����С���");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("��������æ���ء�");

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");	// frost blade cast only.


	if( me->query("max_mp") < 5000 && !me->query("env/yesiknow") )
		return notify_fail("�������������ʹ�����С�");

//	int i;
//	i=me->query("mp")/2;
	if( !me->query("env/yesiknow") )
		me->add("max_mp",-5000);

	message_vision("���������С�",me);
	message_vision("���˼���ͬʱ�����֣�$n���ٶȺÿ죬��$N��$N��$N�㿪�ˡ�",target,me);
	message_vision("��$N����������ȥ�ˣ�$N�����������ˣ�$N����ʹ�������С�",target,me);
	message_vision("$n��һֻ�ֵ����˵أ���ɫ��û�б䣬�ú��ӣ�",target,me);
	message_vision("$N�����ֳ���һ����������$n�Ľ��ϡ����⴩��$n�Ľš�",target,me);
	message_vision("�ú��ӣ�$n��Ȼ��$N����һ����$n�·����ˣ�",target,me);
	message_vision("$N�ٴο�����$n��һֻ�š�$n��Ȼ���˹���һ����",target,me);
	message_vision("$Nû��ʱ���ٱ���$n�Ǻú��ӡ�$N�����˰�ʮһ����ÿһ������$n�ֳ����룡",target,me);
	message_vision("...",target,me);
	message_vision("$Nת���뿪���紵��$N��ͷ����$N��������$n��ͷ��",target,me);
	me->receive_damage("hp",1,target);
	me->die();
	message_vision("��Ȼ�䣬$N����$N��ͷ�뿪�����壬$N����л�ͷ����һ�£�ԭ�������$n��һֻ�ֻ����ŵ�������",target,me);
	message_vision("������������������������ ",target,me);
	target->receive_damage("hp",1,me);
	target->die();

	return 1;
}

static int do_suicidalb(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�");

	if( !target->Query(IS_LIVING))
		return notify_fail("����û�б�Ҫʹ�����С���");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("��������æ���ء�");

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");	// frost blade cast only.


	if( me->query("max_mp") < 5000)
		return notify_fail("�������������ʹ�����С�");

//	int i;
//	i=me->query("mp")/2;
	me->add("max_mp",-5000);

	message_vision("���������С�",me);
	message_vision("���˼���ͬʱ�����֣�$n���ٶȺÿ죬��$N��$N��$N�㿪�ˡ�",me,target);
	message_vision("��$N����������ȥ�ˣ�$N�����������ˣ�$N����ʹ�������С�",me,target);
	message_vision("$n��һֻ�ֵ����˵أ���ɫ��û�б䣬�ú��ӣ�",me,target);
	message_vision("$N�����ֳ���һ����������$n�Ľ��ϡ����⴩��$n�Ľš�",me,target);
	message_vision("�ú��ӣ�$n��Ȼ��$N����һ����$n�·����ˣ�",me,target);
	message_vision("$N�ٴο�����$n��һֻ�š�$n��Ȼ���˹���һ����",me,target);
	message_vision("$Nû��ʱ���ٱ���$n�Ǻú��ӡ�$N�����˰�ʮһ����ÿһ������$n�ֳ����룡",me,target);
	message_vision("...",me,target);
	message_vision("$Nת���뿪���紵��$N��ͷ����$N��������$n��ͷ��",me,target);
	target->receive_damage("hp",1,me);
	target->die();
	message_vision("��Ȼ�䣬$N����$N��ͷ�뿪�����壬$N����л�ͷ����һ�£�ԭ�������$nʣ�µ�һֻ�ֻ����ŵ�������",me,target);
	message_vision("������������������������ ",me,target);
	me->receive_damage("hp",1,target);
	me->die();

	return 1;
}

*/

SKILL_END;
