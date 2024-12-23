//longnv.h
//code by zwb
//12-23

NPC_BEGIN(CNGuMu_yangguo);

virtual void create()
{
	set_name("����","guo er");
	
	set("gender", "����");
	set("age", 38);
	set("long","����һλ�ߴ�����ӣ���ò���㡣һֻ����տ���Ҳ�����Ƕ���һ�ۣ�������ˣ���Ȼ�ڲ�ס�����˵ķ�ɡ�");
	set("title","����쳾");
	set("attitude", "friendly");
	set("icon",young_man1);
	
	set("per", 40);
	set("str", 40);
	set("int", 37);
	set("con", 36);
	set("dex", 58);	
	set("foolid",61);
	set("chat_chance", 10);
	set("chat_chance_combat", 40);
	
	set("hp", 22000);
	set("max_hp", 22000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_factor", 200);
	
	set("combat_exp", 54000000);
	
	set_skill("force", 220);
	set_skill("yunv_xinfa", 220);	//��Ů�ķ�
	set_skill("seaforce", 300);		//���ķ�
	
	set_skill("sword", 300);
	set_skill("yunv_jian", 260);
	set_skill("smithsword",300);	//�����ؽ�ʽ
	
	set_skill("dodge", 260);
	set_skill("xianyun_bufa", 260);	//���Ʋ���
	
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("meinv_quan", 220);    
	set_skill("anranxiaohun_zhang", 300);
	set_skill("tianluo_diwang", 220);
	
	set_skill("literate", 260);
	
	map_skill("force", "seaforce");
	map_skill("sword", "smithsword");
	map_skill("dodge", "xianyun_bufa");
	map_skill("parry", "anranxiaohun_zhang");
	map_skill("unarmed", "anranxiaohun_zhang");
	
	create_family("��Ĺ��", 3, "����");
	
	set_inquiry("�����ؽ�ʽ","�����ؽ�ʽ�������٣����ڴ󳱡�");
	set_inquiry("��Ĺ��","�Һ�����������һ����ˣ�����...");
	set_inquiry("���鵤",do_jueqingdan);
	set_inquiry("�����","����λ����Ҳ��֪�����ǣ���ȥ���ʰ�������");
	set_inquiry("������","������һ��Ϣ��ͨ���ˣ����ڳɶ���");
	set_inquiry("��ȥ","����ʲô����Ҫ�ܳ�ȥ�����ȥ�ˣ�");
	
	carry_object("xuantiesword")->wield();	

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("no_huan",1);
}

static char * do_jueqingdan(CNpc *who,CChar *me)
{
//	if(DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��"))
//		return "����üͷһ������㲻�����ǹ�Ĺ���ӣ�����ô���鷳���أ�";
			
	if ( me->query("repute") < 100000)
		return "����̾��һ����˵�����������ô�ͣ���ô���Խ����˾����ѽ��";

	if ( me->query_temp("gumu/jq_dan_ok") )
		return "������ϲ��˵����������õ��˾��鵤����";

	if ( me->query("gumu/jq")==me->query("age") )
		return "�����Ǻ�һЦ���Ҽǵ����Ѿ������ҵ��˾��鵤��ѽ��";
	
	if(!me->query_temp("gumu/jq_dan"))
	{
		who->say("���������黨֮������Ҫ���鵤�ⶾ�����ܰ����ҵ���", me);
		who->SendMenu(me);
		me->del("gumu/���");
		me->set_temp("gumu/jq_dan",1);
	}
	else
	{
		if(random(1))
			who->say("���鵤Ӧ��ֻ�о���ȹ������У���֪�����ܲ��ܴ��������õ���", me);
		else
			who->say("����Ⱦ���λ����Ҳ��֪�����ǣ�ֻ�С���������ͨ��������֪�������", me);
		who->SendMenu(me);
	}
	return 0;
}

virtual char * chat_msg_combat(CChar * player)
{
//	char msg[255];	
	switch(random(3))
	{
	case 1:
		perform_action("unarmed anranxiaohun", 1);
		return 0;
	case 2:
		perform_action("force recover", 0);
	}
	return 0;
}

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "������������������������������������������������������";
	case 1:
		return "����������Ȼ�����ţ�Ω����ѡ�";
	case 2:
		return "���������������ǣ��Ƕ������������ڰ������Ǻβ���";
	}
	return "";
}

virtual void attempt_apprentice(CChar  * player)
{
	if (!player->query_temp("hjcss"))
	{
		say("�������������",player);
		SendMenu(player);
		return;
	}
	if(player->query("per") < 28)
	{
		say(" ����ʵ�ڲ��ҹ�ά��������������Ц���ҵġ�",player);
		SendMenu(player);
		return;
	}
	if(player->query_int() < 35)
	{
		say(" ������ô����ͽ�ܣ���������Ц���ҲŹ֡�",player);
		SendMenu(player);
		return;
	}
	if(player->query("repute") < 50000)
	{
		say(" �����ϲ�������֮�ˣ�������Ե��",player);
		SendMenu(player);
		return;
	}
	if(DIFFERSTR(player->querystr("family/family_name"), "��Ĺ��"))
	{
		say(" ������������������Ϊͽ�ģ����ȵ���Ĺȥ�������ɡ�",player);
		SendMenu(player);
		return;
	}
	if(EQUALSTR(player->querystr("class"), "taoist"))
	{
		say(" ������ϲ����ʦ��ĵ��ӣ�����ô�����㰡��",player);
		SendMenu(player);
		return;
	}
	else
	{
		say(" �ðɣ��Ҿ����������ͽ���ˡ�");
		recruit_apprentice(player);
	}
	return;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if( EQUALSTR(ob->querystr("base_name"), "junzijian")
		&& who->query_temp("marks/ask_long"))
	{
		command("ah");
		command("faint");
		command("say");
		command("thank");
		who->set_temp("hjcss",1);
		destruct(ob);
		say("���������������ҵİɣ��ܺá��������ɵĻ���˵�ɣ�û���⡣");
		SendMenu(who);
		return 1;	
	}
	else if(EQUALSTR(ob->querystr("id"), "jue qing dan")&& who->query_temp("gumu/jq_dan_ok"))
	{
		destruct(ob);
		say("лл�㣬�鷳������ֱ�ӽ��������ɣ����ڹ�Ĺ��");
		CContainer * bot = load_item("mixian");
		bot->set_name("���鵤", "jue qing dan");
		bot->set("long","���ķ������Ӱ�ĵ�ҩ��ɫ����ڣ��ȳ��̱ǣ���ʹ�����滨���黨���Ķ��Ž�ҩ��");
		bot->set("value", 0l);      
		bot->set("unit", "��");
		bot->move(who);
		who->delete_temp("gumu/jq_dan_ok");
		who->set_temp("gumu/jq_dan_nv",1);
		SendMenu(who);
		return 1;
	}
	else
		return 0;
}

NPC_END;




