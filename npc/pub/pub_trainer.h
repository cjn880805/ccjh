//pub_trainer.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_trainer);

virtual void create()
{
	set_name("����",  "trainer");

	set("icon", triggerman1);
	set("gender", "����" );
	set("age", 25);
	set("long", "���Ǹ��Ͱ����׵Ľ�����");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	set("max_hp", 900);
	set("mp", 200);
	set("max_mp", 200);
	set("combat_exp", 30000);
	set("score", 20000);
	set_skill("force", 60);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 60);
	set_skill("staff",60);
	
	create_family("����ɽ��",5,"����");
}

virtual char * greeting(CChar * ob)
{
	if ( EQUALSTR(ob->querystr("family/family_name"), "����ɽ��"))
	{ 
		if(ob->query("hp")<60)
			message_vision("��������$NЦ���������۰ɣ�û��ϵ���ྡ�����",ob);
		else
			message_vision("��������$N���������������������ɼΣ�",ob);
	}
	return "";
}

virtual void attempt_apprentice(CChar * ob)
{
	say("�Ҳ�����ͽ���㻹�ǰ����ͷ�ɡ�", ob);
	SendMenu(ob);
	return;
}

virtual int accept_fight(CChar * ob)
{
	if ( EQUALSTR(ob->querystr("family/family_name"), "����ɽ��"))
	{
		if( ob->query("combat_exp")<10000)
			return notify_fail("����Ц������ľ���̫���ˣ�����������ͯ�ӱȻ��ɣ�(bi tongzi)");
	}
    return 1;
}

NPC_END;