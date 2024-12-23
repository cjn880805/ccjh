//hong.h
//code by cat
//2001-4-2

NPC_BEGIN(CNGuMu_hong);

virtual void create()
{
	set_name("����","hong lingling");

	set("gender", "Ů��");
	set("age", 24);
	set("long","����ɫ���� ��˫���κ죬����ˮ�����ġ����˿��˻��뿴��");
	set("attitude", "friendly");
	set("icon",taoistess);
	set("rank_info/respect", "����");
set("foolid",57);	
	set("per", 27);
	set("str", 26);
	set("int", 25);
	set("con", 17);
	set("dex", 35);
	set("shen_type", -1);
	set("hp", 3500);
	set("max_hp", 5400);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 40);
	
	set("combat_exp", 800000);
	set("score", 5000);
	
	set_skill("force", 100);
	set_skill("yunv_xinfa", 100);    //��Ů�ķ�
	set_skill("sword", 120);
	set_skill("yunv_jian", 120);     //��Ů��
	set_skill("dodge", 120);
	set_skill("yunv_shenfa", 120);   //��Ů��
	set_skill("parry", 100);
	set_skill("unarmed",100);
	set_skill("wudu_shenzhang", 100);    //�嶾����
	set_skill("wudu_xinfa", 100);
	set_skill("swsb_whip", 100);
	set_skill("whip", 100);
	set_skill("literate",100);
	set_skill("tianluo_diwang", 150);
	
	map_skill("force", "yunv_xinfa");
	map_skill("sword", "yunv_jian");
	map_skill("dodge", "yunv_shenfa");
	map_skill("parry", "swsb_whip");
	map_skill("whip", "swsb_whip");
	map_skill("unarmed", "wudu_shenzhang");
	
	create_family("��Ĺ��", 4, "����");
	set("chat_chance_combat", 30);
	set_inquiry("��������", "������ʦ���Ķ��Ű�������˵�Ǹ�����Ҳ��һ������룬��֪�����ǱߵĶ�����ô����");
	
	carry_object("daogu_cloth")->wear();
	carry_object("fuchen")->wield();
	set("no_huan",1);
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("unarmed you", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}
	return 0;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "fengmi") || DIFFERSTR(ob->querystr("name"), "�����") )
	{	
		message_vision("$N����ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("jingxin_san");

	message_vision("$N����$nһƿ���Ŀڷ�Һ������������ķ��۾����ҳ������Ľ�ҩ����лл����", this, who);
	ob->move(who);

	return 1;
}

virtual void attempt_apprentice(CChar  * player)
{
	if(player->query("per") < 20)
	{
		say(" ����ʵ�ڲ��ҹ�ά������ѧ������Ů�ķ���",player);
		SendMenu(player);
		return;
	}
	if(player->query_dex() < 20)
	{
		say(" �����̫����ʺ�ѧ�ҹ�Ĺ�ɵ��书��",player);
		SendMenu(player);
		return;
	}
	if(player->query_int() < 25)
	{
		say(" �������̫����ʺ�ѧ�ҹ�Ĺ�ɵ��书��",player);
		SendMenu(player);
		return;
	}
	if(player->query("repute") > 0)
	{
		say(" ����������磬��ʦ������ϲ���ġ�",player);
		SendMenu(player);
		return;
	}
	if((EQUALSTR(player->querystr("family/family_name"), "��Ĺ��")) && (DIFFERSTR(player->querystr("class"), "taoist")) )
	{
		say(" �㲻ȥ��ص������������Ҹ�ʲô��",player);
		SendMenu(player);
		return;
	}
	if(DIFFERSTR(player->querystr("gender"), "Ů��"))
	{
		say("�Բ��𣬱���ֻ��Ů���ӣ�����������һ��ȥ��",player);
		SendMenu(player);
		return;
	}
	else
	{
		player->set("class", "taoist");
	    say(" �ðɣ��Ҿ����������ͽ���ˡ�");
		recruit_apprentice(player);
	}
	return;
}
NPC_END;
