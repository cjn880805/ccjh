//sun.h
//code by cat
//2001-4-2

NPC_BEGIN(CNGuMu_sun);

virtual void create()
{
	set_name("������","sun nana");
	
	set("gender", "Ů��");
	set("age", 58);
	set("long",
		"����һ���Ͱ����׵������ţ�һ��������Ƥ���ĳ���,�����֮��ȴ���ʴ�����֮��.");
	set("attitude", "friendly");
	set("icon",old_woman);
	
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("foolid",60);
	set("chat_chance_combat", 9);
	
	set("chat_chance", 1);
	
	set("hp", 3500);
	set("max_hp", 5400);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 40);
	
	set("combat_exp", 1000000);
	
	
	set_skill("force", 150);
	set_skill("yunv_xinfa", 150);    //��Ů�ķ�
	set_skill("sword", 150);
	set_skill("yunv_jian", 150);     //��Ů��
	set_skill("dodge", 160);
	set_skill("yunv_shenfa", 160);   //��Ů��
	set_skill("parry", 130);
	set_skill("unarmed",100);
	set_skill("meinv_quan", 120);    //��Ůȭ��
	set_skill("literate",120);
	set_skill("qufeng",100);         //����֮��
	set_skill("tianluo_diwang", 150);
	
	map_skill("force", "yunv_xinfa");
	map_skill("sword", "yunv_jian");
	map_skill("dodge", "yunv_shenfa");
	map_skill("parry", "meinv_quan");
	map_skill("unarmed", "meinv_quan");
	
	create_family("��Ĺ��", 3, "����");
	
	set_inquiry("�����Ĺ","�����صأ�л�����˽��롣");
	set_inquiry("��Ů����","��Ů������ȫ�潣���ϱڣ������޵У�");
	set_inquiry("��Ĺ��","�ҵ�����ʦ���ű�����������ʦ��һ����ˣ�����...");
	set_inquiry("��佬","����佬Ҫ����ۣ������������ˣ��������ŵĶ�����ȥ�����ˡ�");
	
	carry_object("baipao")->wear();
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
	if ( DIFFERSTR(ob->querystr("id"), "fengmi") || DIFFERSTR(ob->querystr("name"), "�����" ))
	{	
		message_vision("$N����ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("honey");

	message_vision("$N����$nһƿ��佬����������������������лл����Ұ��۲ɻ�������", this, who);
	ob->move(who);

	return 1;
}


virtual void attempt_apprentice(CChar  * player)
{
	if(player->query("per") < 25)
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
	if(EQUALSTR(player->querystr("family/family_name"), "��Ĺ��") && EQUALSTR(player->querystr("class"), "taoist"))
	{
		say(" �����Ǹ�ħͷ�����£��������棬�߰ɡ�",player);
		SendMenu(player);
		return;
	}
	if(player->query("repute") < 0)
	{
		say(" ��Ĺ���Ѿ�����һ��ħͷ���Ҳ�Ը�ù�Ĺ����������·�����",player);
		SendMenu(player);
		return;
	}
	if((EQUALSTR(player->querystr("gender"), "����") ) && (! player->query_temp("pending/join_gumu")))
	{
		say(" �����ķ���̫�ʺ�������ϰ�����������û�У���Ҫ���Ӵ��",player);
		SendMenu(player);
		player->set_temp("pending/join_gumu", 1);
		return;
	}
	if(EQUALSTR(player->querystr("gender"), "����"))
	{
		say("�����@#%%^&^&##!@#@$^$(&(%#$E#",player);
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
NPC_END;
