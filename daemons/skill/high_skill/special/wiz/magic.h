// magic.c ���� Monsterר��
// Lanwood
// 2001-02-03

FORCE_BEGIN(CSmagic);

virtual void create()
{
	CForce::create();

	set_name( "����");

	Magic_t * magic;

	magic = add_magic("lieyan", do_lieyan);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("heal", do_heal);
	magic->name = "ˮ����";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;


	magic = add_magic("oildown", do_oildown);
	magic->name = "���̷��ͽ�";
	magic->mp = 150;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("powerheal", do_powerheal);
	magic->name = "������";
	magic->mp = 80;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("meteor", do_meteor);
	magic->name = "���Ǳ�����";
	magic->mp = 300;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;

}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("����ֻ����ѧ�������������ȡ�");
}

static int do_lieyan(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -100);

	message_vision("$N���һ����ָ�����������д�~~~ֻ��һ���Ż�����������", me);

	static char flee_msg[4][80] ={
		"���$N����һԾ�������ӹ�һ�٣�",
		"$N�ŵ���ɫ�԰ף�����û���˵���ë��",
		"$N�͵�һ�����㿪�˻��档",		
		"$N����ײײ����Ũ���������������ӹ�һ�٣�",
	};
	static char attack_msg[7][80] = {
		"$N�������������ǵ���ͷ����(-%ld)",
		"$N�ŵ���ɫ�԰ף��·���������ȥ��һ�ǣ�(-%ld)",
		"$Nͷ������ŵÿ޵����(-%ld)",
		"$N�Һ�һ������������ȥ��ͷ����(-%ld)",
		"$Nȫ�������Χ���ŵ����۴�ޣ�(-%ld)",
		"$N�����������Ȼû�ӳ�����İ�Χ��(-%ld)",
		"$N�������յý�ͷ�ö��Ũ������ײ��(-%ld)",		
	};

	//������������ȫ�壡
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(! target->is_fighting(me)) continue;
		
		int flee = 0;
		if(target->query_skill("force") > 150 && random(2) == 0)
			flee = 1;
		else if(target->query_skill("force") > 100 && random(3) == 0)
			flee = 1;
		else if(target->query_skill("force") > 50 && random(5) == 0)
			flee = 1;
		else if(random(7) == 0)
			flee = 1;

		if(! flee)
		{
			int lvl = random(7);
			LONG damage = me->query("level") * (lvl + 1) * 2;
			damage = (damage + random(damage)) / 2;
			snprintf(msg, 255, attack_msg[lvl], damage);
			target->receive_damage("hp", damage);
			target->start_busy(2);
			target->SendState();
		}
		else
		{
			strcpy(msg, flee_msg[random(4)]);
			target->start_busy(1);
		}

		message_vision(msg, target);
	}

	me->start_busy(5);
	return 1;
}

//ˮ����
static int do_heal(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 50) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -50);

	message_vision("$N˫�ֺ�ʮ����¶��֮ɫ��ֻ��һƬѩ��Ʈ������", me);

	static char heal_msg[4][80] = {
		"$N��ԡ��ѩ���У��پ�����Ŀ����(+%ld)",
		"$N������������ڣ���ʱ�ָ�����ɫ��(+%ld)",
		"$N��ԡ��ѩ���У����۷ų���ʣ�(+%ld)",
		"ѩ��Ʈ����$N��ʱ������ʷ��(+%ld)"		
	};

	//����ȫ�壡
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(target != me && ! target->is_fighting() )
			continue;

		if(target->query_temp("fight/fight_team") != me->query_temp("fight/fight_team"))
			continue;
		
		int lvl = random(4);
		
		LONG heal = me->query("level") * (lvl + 1) * 2;
		
		heal = (heal + random(heal)) / 2;
		snprintf(msg, 255, heal_msg[lvl], heal);
		target->receive_healing("hp", heal);
		target->SendState();
		
		message_vision(msg, target);
	}

	me->start_busy(5);
	return 1;
}



//������
static int do_powerheal(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 80) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -80);

	message_vision("$N����һ����һ�������Ե������𡭡�", me);

	static char heal_msg[4][80] = {
		"$N��Ũ���д�Ц�������������������㣡(+%ld)",
		"$N������������ڣ���ʱ�ָ�����ɫ��(+%ld)",
		"$N�������е�����Խ����(+%ld)",
		"������$N��������Ȧ������$N���ڣ�(+%ld)"		
	};

	//����ȫ�壡
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(target != me && ! target->is_fighting() )
			continue;

		if(target->query_temp("fight/fight_team") != me->query_temp("fight/fight_team"))
			continue;
		
		int lvl = random(4);
		
		LONG heal = me->query("level") * (lvl + 1) * 2;
		
		heal = (heal + random(heal)) ;
		snprintf(msg, 255, heal_msg[lvl], heal);
		target->receive_healing("hp", heal);
		target->SendState();
		
		message_vision(msg, target);
	}

	me->start_busy(3);
	return 1;
}

static int do_oildown(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 150) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -150);

	message_vision("$N�߾�˫�֣����������дǣ��͵�����һ�ӣ�", me);
	message_vision("һ������̵ķ��������Ͻ��£�", me);

	static char flee_msg[4][80] ={
		"���$N����һԾ�������ӹ�һ�٣�",
		"$N�ŵ���ɫ�԰ף�����û���˵���ë��",
		"$N������һ�������ͱ����С�",		
		"$N����һ����Ѹ�ݵ����˿�ȥ��",
	};
	static char attack_msg[7][80] = {
		"$N�������������õ��˽�ֺ��(-%ld)",
		"$N�������������õ��˽�ֺ��(-%ld)",
		"$N�ŵ���ɫ�԰ף��·������У���ʱһƬ���ڣ�(-%ld)",
		"$N�ŵ���ɫ�԰ף��·������У���ʱһƬ���ڣ�(-%ld)",
		"$N�ҽ�һ���������˸����ţ�(-%ld)",
		"$N���������ӿ������̫��һ����������У���ʱ����������(-%ld)",
		"$N��һ������һ��������һ������ǰ��һ�����պ�վ��һ���������£�(-%ld)",
	};

	//���̷��ͽ�������ȫ�壡
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(! target->is_fighting(me)) continue;
		
		int flee = 0;
		if(target->query_skill("dodge") > 150 && random(3) == 0)
			flee = 1;
		else if(target->query_skill("dodge") > 100 && random(5) == 0)
			flee = 1;
		else if(target->query_skill("dodge") > 50 && random(7) == 0)
			flee = 1;
		else if(random(9) == 0)
			flee = 1;

		if(! flee)
		{
			int lvl = random(7);
			LONG damage = me->query("level") * (lvl + 1) * 2;
			damage = (damage + random(damage)) *2 / 3;
			snprintf(msg, 255, attack_msg[lvl], damage);
			target->receive_damage("hp", damage);
			target->start_busy(2);
			target->SendState();
		}
		else
		{
			strcpy(msg, flee_msg[random(4)]);
			target->start_busy(1);
		}

		message_vision(msg, target);
	}

	me->start_busy(5);
	return 1;
}


//���Ǳ�����
static int do_meteor(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 300) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -300);

	message_vision("$N���������дʣ����ֳ���һָ��", me);
	message_vision("ֻ���ú�Х�ƿ�֮����һƬ�������ս�����£�", me);

	static char flee_msg[2][80] ={
		"$N������һ����һ�����Ǳ�����$N�ղ�վ���ĵط���",		
		"$N�ڵ���һ��������û�ܿ���",
	};
	static char attack_msg[3][80] = {
		"$N�ҽ�һ���������˸�ͷ��Ѫ����(-%ld)",
		"$N���������ӿ������̫��һ����һͷײ��һ����ʯ�ϣ�(-%ld)",
		"$N��һ������һ��������һ������ǰ��һ�����պ�վ��һƬ�����£�(-%ld)",
	};

	//���Ǳ�����������ȫ�壡
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(! target->is_fighting(me)) continue;
		
		int flee = 0;
		if(target->query_skill("dodge") > 200 && random(4) == 0)
			flee = 1;
		else if(target->query_skill("dodge") > 160 && random(7) == 0)
			flee = 1;
		else if(target->query_skill("dodge") > 120 && random(10) == 0)
			flee = 1;
		else if(random(20) == 0)
			flee = 1;

		if(! flee)
		{
			int lvl = random(3);
			LONG damage = me->query("level") * (lvl*2 + 2) * 2;
			damage = (damage + random(damage)) *3/2;
			snprintf(msg, 255, attack_msg[lvl], damage);
			target->receive_wound("hp", damage);
			target->start_busy(3);
			target->SendState();
		}
		else
		{
			strcpy(msg, flee_msg[random(2)]);
			target->start_busy(3);
		}

		message_vision(msg, target);
	}

	me->start_busy(9);
	return 1;
}



FORCE_END;
