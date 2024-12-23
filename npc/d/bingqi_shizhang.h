//shizhang.h
//code by zwb
//12-16

NPC_BEGIN(CNBingQi_shizhang);

virtual void create()
{
	set_name("����","shi zhang");

	set("nickname","��");
	set("gender", "����" );
	set("age", 20);
	set("long","��ͷ�ϰ����ϲ�ͷ��һϮ������û��һ˿���塣");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	
	set("max_mp",500);
	set("mp_factor",50);
 	set("icon",young_man1);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("parry",90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);

	set("combat_exp", 250000);
	
	
	set("attitude", "peaceful");
        
	set_inquiry("����","ʦ�����Ұ����������ȣ���������Ҳ����һ����Ӱ��˭Ҫ�����أ�");
	set_inquiry("ԭ��","���ȿ��ú�˿���񣬺��׽�ĸ��ǧ����ľ����Ч������һ����");

	carry_object("cloth")->wear();
	set("no_huan",1);
};



virtual int accept_object(CChar * player,CContainer * ob)
{
	string name;
	char msg[255];

	if(!(player->query_temp("staff")))
	{
		say("ʦ��û��ͬ��Ϊ�����ȣ�����ذɣ�",player);
		SendMenu(player);
		return 1;
	}
	player->delete_temp("staff");
	player->set_temp("m_staff",1);
	name = ob->querystr("id");

	if(name == "shen mu")
	{
		player->add_temp("shen mu",1);
	}
	else if(name == "jin mu")
	{
		player->add_temp("jin mu",1);
	}
	else if(name == "hanzhu")
	{
		player->add_temp("hanzhu",1);
	}
	else
	{
		say("����ʲô��ʦ��˵�ⲻ���������������",player);
		SendMenu(player);
		return 0;
	}

	say(snprintf(msg,255,"���ȵ�ͷ������һ�����е�%s���˵�ͷ˵�����������������ھͿ�ʼ����",ob->query("name")),player);
	say(snprintf(msg,255,"����λ%s���������ְɣ�",query_respect(player)),player);
	AddMenuItem("��������������֣�", "$2zhu $1 $2", player);
	AddMenuItem("��ı����ⲻ���������ˡ�", "", player);
	SendMenu(player);
	return 2;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(comm == "zhu")
		return do_zhu(me, arg);

	return 0;
}

int do_zhu(CChar * player, char * arg)
{
	CContainer * staff;
	CChar * npc=(CChar *)this;
	char		o_name[40],w_name[40];
	char		msg[255];


	if(!(player->query_temp("m_staff")))
		return notify_fail("ʲô?");
	player->delete_temp("m_staff");
	player->delete_temp("get_orc");
	player->delete_temp("or");

	if(player->query("weapon/make"))
	{
		say("����һ��ãȻ�����Ѿ���һ������������ˣ�������ʲô���ѵ�������ô��", player);
		SendMenu(player);
		return 2;
	}

	if(! strlen(arg) )
		return notify_fail("���������˵������ȵ������ٶ���˵��");

	sscanf(arg,"%s",w_name);

	if(player->query_temp("shen mu")) strcpy(o_name,"ǧ����ľ");
	if(player->query_temp("jin mu")) strcpy(o_name,"���׽�ĸ");
	if(player->query_temp("hanzhu")) strcpy(o_name,"��˿����");

//	make_time=NATURE_D->game_time();

	message_vision(snprintf(msg,255,"%s������һ�ᣬ����������˵�˼��仰�����ȵ��˵�ͷ��˵���ðɣ�",player->name()),player);
	message_vision(snprintf(msg,255,"$N˫����סһ���޴�����ȣ��͵���¯�н�������������%s��ȥ��",o_name),player);
	message_vision(snprintf(msg,255,"ֻ�������һ�����죬��ͷ��%sճ����һ��",o_name ),player);
	message_vision("$Nֻ��������һ�ȣ������ѪҺ�ƺ���������������" ,player);
	message_vision(snprintf(msg,255,"һ��Ѫ�����������������ԴԴ���ϵ���¯�е�ӿȥ��",o_name),player); 

	if((player->query("hp")) < (player->query("max_hp")) || (player->query("mp")) < (player->query("max_mp")))
	{
		message_vision("ͻȻ$N������Ѫһ��ӿ��һ�������Ӳ�������������",player);
		player->set("mp",0l);
		player->unconcious();
		return 1;
	}

	message_vision("ֻ������һ�����죬һ�����ȴ�¯��ٿȻԾ�𡣻���һ������͵���$N��ǰ�ش�������",player);
	message_vision("���ȼ�״��У����ȳ��ɣ���Ѫ�Լ�����������",player);
	message_vision("$Nֻ������ǰһ����һ����ӰѸ���ޱȵĵ�����$N����ǰ��",player);
	message_vision("����͸�ش��������ȲҺ�һ������Ѫ�������������ǣ�",player);
	message_vision("���Ƚ���һ�����ȣ������˵��ϡ������Ѿ�����һϢ�ˡ�",player);

	npc->set("max_hp",10);

	message_vision("�����ַ����������ɵ���գ�����һ����ص����ϡ�¯�еĻ����ˡ�һ�ҵľ����������Σ�һ���ֹ��ڳ��š�",player);

	player->set("hp",10);
	player->set("mp",0l);

	player->set("weapon/make",1);		
	player->set("weapon/name",w_name);	
//	player->set("weapon/id",id);		
	player->set("weapon/lv",1);    	
	player->set("weapon/or",o_name);	
	player->set("weapon/value",0l);	      		
	player->set("weapon/type","��");
//	player->set("weapon/time",make_time);

	staff=load_item("m_staff");	
	staff->move(player);
	message_vision("����������ϣ����Ű߰�Ѫ������Щ���ֵľ��ȣ�˵���ȡ����ѡ����ɡ��������ȵ����񡣡���Ҳ������ˡ�������",player );
	message_vision("���ȼ��ѵ�˵���ȡ����������պã��Ҹ����ˡ�����",player);
	message_vision("����˵�ꡣٿ�ı㲻���ˡ�",player);
	npc->die();
	return 1;
}
NPC_END;
