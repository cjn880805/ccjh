// linzhennan.c ������
//sound 2001-07-18

NPC_BEGIN(CNfuzhou_linzhennan);

virtual void create()
{
	set_name("������", "lin zhennan");
	set("gender", "����");
	set("age", 45);
	set("icon",triggerman1);
	set("long", "�����ǡ������ھ֡�������ͷ������������");
	
	set("combat_exp", 30000);
	set("shen_type", 1);
	
	set("max_mp", 500);
	set("mp", 500);
	set("mp_factor", 10);
	
	set_skill("force", 40);
	set_skill("sword", 50);
	set_skill("pixie_sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	map_skill("parry", "pixie_sword");
	map_skill("sword", "pixie_sword");
//	set("price", 100000);	

	set_inquiry("������լ", "������˵���������Ҵ�ǰ�ڸ���ʱס�ļ�Ժ���Ѿ��ư��ˡ�");
	set_inquiry("��ͼԶ", "��������ŭ��С������ôû��ò��ֱ���������䣡");
	set_inquiry("��������", "�ȸ���Ѻ����˵�������ڳ�18�򡢴����ڳ�10������8��С��5�򡣿����������Ҫ�����ˡ�");
	set_inquiry("Ѻ�˰���", "������������������С����˵�����߰����������������������ҿɶ�����ġ���Ѻ30000Ѻ��ɣ�");
	set_inquiry("Ƹ��������", ask_dashou);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
//	set("����",1);  //���ڿ���
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	set("no_huan",1);
};

static char * ask_dashou(CNpc * npc , CChar * player)
{
	if(player->query_temp("biaoche/owner"))
	{
		if(player->query_temp("biaoche/money"))
		{
			player->delete_temp("biaoche/money");
			player->delete_temp("biaoche/owner");
			player->set_temp("biaoche/tangzishou",1);
			return "������˵�����ðɣ���Ȼ����Լ����Ĳ��㣬�Ҿ��ɸ�������������һ�˰ɣ�";
		}
		else
		{
			player->set_temp("biaoche/dashou",1);
			return "������˵�����ھ��������һֱ�Ƚ�æ����ʵ�����ڲ���ʲô����ѽ�������ɣ�����Ҹ�15�����ٿ��ǿ��ǡ�";
		}
	}
	else
		return "������˵����������������ʲô����";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * bot1;
	char msg[255];
	if(who->is_busy())
		return notify_fail("����һ��������û�����");

	if (DIFFERSTR(ob->querystr("id"), "coin") )
	{	
		say("���ӳ���������Ҫ����Ѻ��ģ��������ڴ������Ĺ�أ�", who);
		SendMenu(who);
		return 0;
	}
	if (ob->query("value") ==30000 && query("����") && !who->query_temp("lin/baoguo/start"))
	{
		static char obj_man[15][20]={"inlun fawang","ding","xiaoyao nv","zhang sanfeng","huang laoguai","xuanci dashi", "wang chongyang",
			"zhang wudi","tie lao","yue bufan","long er","hong qigong","miejin shitai","duan zhengpu","ouyang feng"};
		static char obj_name[15][20]={"��������","������","��ңŮ","������","���Ϲ�","���ʹ�ʦ", "������",
			"���޵�","��ɽ����","������","����","��л�","��ʦ̫","������","����ׯ��"};
		
		int id=random(15);
		tell_object(who,"\n$HIR���������ĵ���������һ������������ϸһ����ԭ��ֻ�Ǹ�������");
		tell_object(who,snprintf(msg, 255,"$HIR������ѹ���˺����������ĺ���˵���������������������ĵ��͸�%s���³�֮�󣬱�����л��\n", obj_name[id]));
		bot1 = load_item("baoguo");
		bot1->set("owner1",who->id(1));
		bot1->set("obj",obj_man[id]);
		int exp,repute;
		if(who->query("level")<80)
		{
			exp=int(who->query("level")*(10+who->query_temp("lin/baoguo/count")*(1+random(2)))/2);
			exp=int(exp/2+random(int(exp/2)));
			if(exp>3500) exp=3000+random(500);
			repute=int(who->query("level")*(10+who->query_temp("lin/baoguo/count")*(1+random(2)))/5);
			repute=int(repute/2+random(int(repute/2)));
			if(repute>2500) repute=2000+random(500);
			if(who->query("repute")>0)repute=-repute;
			if(who->query_temp("lin/baoguo/count")>150 && !random(3))
				who->set_temp("lin/baoguo/count",int(who->query_temp("lin/baoguo/count")/(random(3)+1)));
		}
		else
		{
			exp=int(who->query("level")*(10+who->query_temp("lin/baoguo/count")*(1+random(2)))/2);
			exp=int(exp/4+random(int(exp/4)));
			if(exp>6000) exp=5000+random(1000);
			repute=int(who->query("level")*(10+who->query_temp("lin/baoguo/count")*(1+random(2)))/5);
			repute=int(repute/4+random(int(repute/4)));
			if(repute>4000) repute=3000+random(1000);
			if(who->query("repute")>0)repute=-repute;
			if(who->query_temp("lin/baoguo/count")>150 && !random(3))
				who->set_temp("lin/baoguo/count",int(who->query_temp("lin/baoguo/count")/(random(3)+1)));
		}
		bot1->set("exp",exp);
		bot1->set("repute",repute);
		bot1->move(who);

		who->set_temp("lin/baoguo/start",1);
		who->set_temp("no_fei",1);
		who->set_weight(50000000);
		destruct(ob);
		return 1;
	}
	else if ((ob->query("value") !=180000)&&(ob->query("value") !=100000) && (ob->query("value") !=80000) &&(ob->query("value") !=50000))
	{	
		if (ob->query("value") ==150000 && who->query_temp("biaoche/dashou"))
		{
			who->set_temp("biaoche/money",1);
			who->delete_temp("biaoche/dashou");
			destruct(ob);
			return 1;
		}
		else
		{
			say("�����ڳ�18��Ѻ�𡢴����ڳ�10��Ѻ�������ڳ�8��Ѻ��С���ڳ�5��Ѻ��", who);
			say("������۸��ˣ��ڳ�һ���Ƴ����Ų��˻��ġ�", who);
			message_vision(snprintf(msg, 255, "�㸶��%d��Ǯ��",ob->query("value")),this);
			SendMenu(who);
		}
		return 0;
	}

	CChar * bot = load_npc("wiz_biaoche");
	bot->set("����",who->querystr("id"));
	if( ob->query("value") ==180000)
	{
		bot->set_name(snprintf(msg, 40, "%s�ľ����ڳ�", who->name(1)));
		bot->set("type",6);//�����ڳ���߾��齱��Ϊ3��+7ǧ�����ڳ���HP��������������
		bot->set("max_lev",180);
		bot->set("min_lev",130);
		bot->set("lev",4);
	}
	else if( ob->query("value") ==100000)
	{
		bot->set_name(snprintf(msg, 40, "%s�Ĵ����ڳ�", who->name(1)));
		bot->set("type",10*0.8);//�����ڳ���߾��齱��Ϊ1��8ǧ+4ǧ5�٣����ڳ���HP��������������
		bot->set("max_lev",160);
		bot->set("min_lev",90);
		bot->set("lev",1);
	}
	else if( ob->query("value") ==80000)
	{
		bot->set_name(snprintf(msg, 40, "%s�������ڳ�", who->name(1)));
		bot->set("type",18*0.8);//�����ڳ���߾��齱��Ϊ1��+2ǧ5�٣����ڳ���HP��������������
		bot->set("max_lev",110);
		bot->set("min_lev",75);
		bot->set("lev",2);
	}
	else
	{
		bot->set_name(snprintf(msg, 40, "%s��С���ڳ�", who->name(1)));
		bot->set("type",25*0.8);//С���ڳ���߾��齱��Ϊ7ǧ+2ǧ�����ڳ���HP��������������
		bot->set("max_lev",90);
		bot->set("min_lev",60);
		bot->set("lev",3);
	}
	bot->move(environment());
	bot->set("ip/ip_address",who->querystr_temp("client/ip_address"));
	bot->set("ip/ip_local",who->querystr_temp("client/ip_local"));
	message_vision("���������˻��֣���������һ���ʷ�����ģ�������ˣ���Ѻ������������", who);
	message_vision("�����ź�Ժ�м����������Ƴ���һ���ڳ�������$N����ǰ��\n", who);

	for(int i=0;i<3;i++)
	{
		bot1 = load_item("biaoqi");
		bot1->set("����",who->querystr("id"));
		bot1->set_name(snprintf(msg, 40, "%s������", who->name(1)));
		bot1->move(who);
	}
	who->set_temp("biaoche/owner",1);
	message_vision("�������ӻ����ͳ�������С�����죬�ݵ�$N�����ϣ�˵�������ڽ�����ȫ��ȭͷ�ǲ��еġ�", who);
	message_vision("��������λ���֣�һ���͸�����һ�����죬���������ڳ����棬���Ž����ϵ����Ѽ����������죬���ٶ����Щ���ӡ�\n", who);
	destruct(ob);
	add("yunbiao_count",1);
	return 1;
}

NPC_END;



