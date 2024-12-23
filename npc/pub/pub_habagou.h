//habagou.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_habagou);

virtual void create()
{
	set_name("���͹�","ha ba gou");
	
	set("icon", dog);
	set("title", "�����ݳ���");
	set("race", "Ұ��");
	set("gender", "����" );
	set("age", 15);
	set("str", 22);
	set("int", 30);
	set("dex", 30);
	set("con", 30);
	
	set("long","�㿴�����ǲ��������С���͹���");
	set("combat_exp", 2000000);
	set("attitude", "friendly");
	
	set("max_hp", 30000);
	set_inquiry("������","������ǣ���Ҫ����");
	set_inquiry("������",ask_me );
};

static char * ask_me(CNpc * npc , CChar * player)
{
	iterator_user p;
	CUser * user;
	
	if ( !wizardp(player) ) return "����Ȩ�ٿ������ᣡ";
	
	for( p = g_UserList.begin(); p!= g_UserList.end(); p++)
	{
		user = p->second;
		user->move(load_room("bobing"));
	}
	
	npc->command("chat ������Ҫ�ۻ��ˣ���ҿ�����");
	return "�ã����ڲ�������ʽ��ʼ��ȫ�弯�ϣ�";
}

virtual int handle_action(char * comm , CChar * player ,char * arg)
{
	if(strcmp(comm, "save") == 0)
		return do_save(player);
	else if(strcmp(comm, "smash") == 0)
		return do_smash(player);
	else if(strcmp(comm, "cast") == 0)
		return do_exert(player);
	
	return 0;
}

int do_save(CChar * player)
{
	char msg[255];
	
	say(snprintf(msg,255, "%s,���������̵ġ�",player->query("name")),player);
	SendMenu(player);
	return 1;
}

int do_smash(CChar * player)
{
	char msg[255];
	
	say(snprintf(msg,255, "%s����ʦ�����Ҳ����ɱ�˵ġ�",player->query("name")),player);
	SendMenu(player);
	return 1;
}

int do_exert(CChar * player)
{
	char msg[255];
	
	say(snprintf(msg,255, "%s��ר�Ĳ����ɣ�",player->query("name")),player);
	SendMenu(player);
	return 1;
}

NPC_END;
