// pub_guidao.c
//code by Fisho

NPC_BEGIN(CNpub_guidao);
 
virtual void create()
{
	set_name("����",   "wang wu"  );

	set("icon", young_man2);
	set("title", "�ƿ�");
	set("gender", "����" );
	set("shen_type", -1);
	set("age", 40);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("long","���Ǹ��ȵ��������ľƹ����������еľƱ��૵���߶��ʲ�ᡣ" );

	set("combat_exp", 20000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);

	set_skill("blade", 50);
	set_skill("dodge", 40);
	set_skill("unarmed", 30);
	set_skill("parry", 50);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();

	set_inquiry("������","������! ��Ȥ��Ȥ����ϧ���ϴ����ˡ�");
	set_inquiry("��",ask_me);
}

virtual char * chat_msg_combat()
{
	switch (random(3) )
	{
	case 0:
		return "����˵��: �㵱����˱��ӵ��� ? �Ҹ���ү���� ! ";
	case 1:
		return "�����Ȼ�ӳ�һ�����������棬��������;ȴ�ּ�æ���С�";
	case 2:
		return "����˵��: ��� ! �������˻����� ?....";
	}
	return "";
}

static char * ask_me(CNpc * who, CChar * me)
{
	if( who->query("revealed") ) 
	{
		if( me->is_killing(who) ) 
			return "���Ȼ֪�����ҵ���֣��������������";
		else 
		{
			who->kill_ob(me);
			//who->fight_ob(ob);
			return "���Ӿ��ǹ����壬��������������ӣ��������ɣ�";
		}
	}

	if( (random(10) < 5) || me->is_fighting() )
		return "�ҡ���֪����";

	who->set_temp("apply/attack",  50);
	who->set_temp("apply/defense", 50);
	who->set_temp("apply/damage",  20);
	who->set("title",  "��" );

	tell_room(me->environment(),"��������ͻȻ�ų������Ĺ�â������˵��������...�㶼֪���ˣ�\n������һ�����е�����Ȼ��ˣ����ӽ��췴�����ȥ������ƴ�ˡ�\n����ʹ���������������棬���ͺ������͸ղŵ�����ֱ�������ˡ�" ,me);

	who->set("pursuer", 1);
	who->set("attitude", "aggressive");
	who->set("vendetta/authority", 1);
	who->set("chat_chance", 15);
	who->set("bellicosity", 10000);
	who->set("combat_exp", 80000);
	who->set_skill("blade", 80);
	who->set_skill("dodge", 70);
	who->set_skill("unarmed", 60);
	who->set_skill("parry", 80);

	who->call_out(all_kill_me, 1);

	who->add_money(500);
	who->set("revealed", 1);
	
	return "���Ӿ��ǹ����壬��������������ӣ��������ɣ�";
}

//ɱ�������
static void all_kill_me(CContainer * ob, LONG param1, LONG param2)
{
	POSITION p;
	CChar * me = (CChar *)ob;
	DTItemList search;
	CContainer * obj;
	CChar * who = NULL;
			
	CopyList(&search, (me->environment())->Get_ItemList());
		
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if(! userp(obj)) continue;
		
		who = (CChar *)obj;
		me->set_killer(who);
		who->set_killer(me);
	}

	if(who)
		me->kill_ob(who);
}

NPC_END;