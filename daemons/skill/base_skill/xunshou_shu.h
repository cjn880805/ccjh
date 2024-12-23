//lingshe_xinfa.h
//ѱ����
//lanwood 2001-05-04

SKILL_BEGIN(CSxunshou_shu);

void create()
{
	set_name( "ѱ����");
	set("special", 1);

	Magic_t * magic;

	magic = add_magic("xiang", do_xiang);
	magic->name = "����";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("summon", do_summon);
	magic->name = "�ٻ�";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

const char * type() { return "knowledge"; }

int valid_learn(CChar * me)
{
	return 1;
}

static int do_xiang(CChar * me, CContainer * ob)
{
	char msg[255];
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || !me->is_fighting(target))
		return notify_fail("���������ս���еĶ���ʹ�ã�");

	if(DIFFERSTR(me->querystr("family/family_name"), "ؤ��")
		&& DIFFERSTR(me->querystr("family/family_name"), "����ɽ��"))
		return notify_fail("ֻ����ؤ����ѱ���߲���ʹ�á�");

	if(me->query_skill("xunshou_shu", 1) < 30)
		return notify_fail("���ѱ������̫ǳ�����ܽ������֣�");

	if(me->is_busy())
		return notify_fail("��������æ��");

	//���ڼ�����
	CContainer * weapon = me->query_weapon();
	if(! weapon || DIFFERSTR(weapon->querystr("skill_type"), "staff") )
		return notify_fail("ѱ�����������ȷ����ʹ�á�");

	if(weapon->querystr("owner")[0])
		return notify_fail("ѱ����������������������ʹ�á�");

	if(me->query("mp") < 150)
		return notify_fail("��ķ������㣡");

	me->add("mp", -150);
	me->start_busy(random(3) + 1);

	int bFail = 0;
	
	if(target->query("monster_lvl"))
	{
		if(DIFFERSTR(weapon->querystr("base_name"), "zijin_staff") )	//�Ͻ�������	�ɽ�������
			bFail = 1;
	}
	else if(! target->querystr("animal")[0])	//���Ƕ���
		bFail = 1;


	//ֻ��hp����30%���п��ܱ��ա�
	if(target->query("hp") > target->query("max_hp") / 3)
		bFail = 1;

	message_vision(snprintf(msg, 255, "$HIM$N�߸�����%s�����������дʣ�ͻȻ���о���һ�֣���$n������ȥ��", weapon->name()), me, target);

	int sp = me->query("level") + me->query_skill("xunshou_shu");
	int	dp = target->query("level") + target->query("monster_lvl") * 10;

	if(bFail || random(sp + dp) < dp)
	{
		message_vision("$HIG$Nȫ�����º�Ȼ�ֳ�һ���̹⣬��âһ�����ʧ�ˡ�", target);
	}
	else	//�ɹ���
	{
		message_vision(snprintf(msg, 255, "$HIGֻ��$n����һ���̹⣬����$N��%s�ϣ�", weapon->name()), me, target);

		//����������������
		if(weapon->querymap("summon") && DIFFERSTR(weapon->querystr("summon/owner"), me->querystr("id")))
		{
			weapon->set_name(weapon->querystr("summon/oldname"));
			weapon->del("summon");			
		}
		
		//����յĵȼ���ԭ���ĸߣ������ӡ�
		if(weapon->query("summon/level") <= target->query("level"))
		{
			weapon->set("summon/monster", target->querystr("base_name"));
			weapon->set("summon/index", target->query("index"));
			weapon->set("summon/owner", me->querystr("id"));
			weapon->set("summon/level", target->query("level"));

			weapon->set("summon/time", weapon->query("summon/time") / 2 + 1);
						
			if(! weapon->querystr("summon/oldname")[0])
				weapon->set("summon/oldname", weapon->querystr("name"));

			weapon->set_name( snprintf(msg, 80, "����%s��%s", target->name(1), weapon->querystr("summon/oldname")));
			weapon->UpdateMe();
		}

		DESTRUCT_OB(target, "xunshou_shu::do_xiang");
	}		
	
	return 1;
}

//�ٻ���
static int do_summon(CChar * me, CContainer * ob)
{
	char msg[255];
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || !me->is_fighting(target))
		return notify_fail("�ٻ������ս���еĶ���ʹ�ã�");

	if(DIFFERSTR(me->querystr("family/family_name"), "ؤ��")
		&& DIFFERSTR(me->querystr("family/family_name"), "����ɽ��"))
		return notify_fail("ֻ����ؤ����ѱ���߲���ʹ�á�");

	if(me->query_skill("xunshou_shu", 1) < 30)
		return notify_fail("���ѱ������̫ǳ�����ܽ������֣�");


	if(me->is_busy())
		return notify_fail("��������æ��");

	CContainer * env = me->environment();

	if(! env->Query(IS_FIGHTROOM)) return 0;

	//���ڼ�����
	CContainer * weapon = me->query_weapon();
	if(! weapon || DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("ѱ�����������ȷ����ʹ�á�");

	if(! weapon->querymap("summon"))
		return notify_fail("û�п����ٻ��Ĺ��");

	//������ġ�
	if(DIFFERSTR(weapon->querystr("summon/owner"), me->querystr("id")))
	{
		weapon->set_name( weapon->querystr("summon/oldname"));
		weapon->del("summon");		
		weapon->UpdateMe();
		return notify_fail("$HIG%s����ͻȻð���������̣���������ֱ����һ����ͨ���ȡ�", weapon->name());
	}

	int team = me->query_team();

	if(! ((CFightRoom *)env)->Can_Join(team) )
		return notify_fail("վ���������޷��ٻ����ޣ�");
	
	if(me->query("mp") < 250)
		return notify_fail("��ķ������㣡");

	me->add("mp", -250);
	
	message_vision(snprintf(msg, 255, "$HIM$N�߸�����%s�����������дʣ�ͻȻ���о���һ�֣���$n������ȥ��", weapon->name()), me, target);

	CNpc * monster = load_npc(weapon->querystr("summon/monster"));
	monster->set("index", weapon->query("summon/index"));
	monster->create();
	monster->move(env);

	if(weapon->add("summon/time", -1) <= 0)
	{
		weapon->set_name( weapon->querystr("summon/oldname"));
		weapon->del("summon");		
		weapon->UpdateMe();
	}
			
	message_vision(snprintf(msg, 255, "$HIG����%s����ð���������̣��������ϵ�%sͻȻ��������", weapon->name(), monster->name()), me);
	
	((CFightRoom *)env)->Join_Team(monster, team);
	g_Combatd.Do_Attack(monster, target, g_Combatd.TYPE_QUICK);

	monster->call_out_combat(do_disappear, me->query_skill("xunshou_shu") * 3); 

	me->start_busy(random(3) + 1);
	
	return 1;
}

static void do_disappear(CContainer * ob, LONG param1, LONG param2)
{
	message_vision("$HIGͻȻһ�����̹�������$N�鴤�˼��£���ʧ����Ӱ���١�", (CChar *)ob);
	ob->call_out(do_disappear2, 1);	
}

static void do_disappear2(CContainer * ob, LONG param1, LONG param2)
{
	DESTRUCT_OB(ob, "xunshou_shu::do_disappear2");
}

SKILL_END;
