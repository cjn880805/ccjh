//hongniang.h
//code by zwb
//12-25


VENDOR_BEGIN(CNpub3_hongniang);


virtual void create()
{
	
	set_name("�ϰ���","LBN");

	set("icon", young_woman2);
	set("title", "����ׯ");
	set("gender", "Ů��" );
	set("age", 16);
	set("per", 36);
	set("long","һλ�����ݵ�С���");
	
	set("max_hp", 2400);
	set("combat_exp", 10000);
	set("attitude", "friendly");
	
	set_skill("literate", 70);
	set_skill("dodge", 200);
	set_skill("unarmed", 100);
	
	carry_good("marry_1", 100, 1);
	carry_good("marry_1", 100, 2);
	carry_good("marry_1", 100, 3);
	carry_good("marry_1", 100, 4);
	carry_good("marry_1", 100, 5);
	carry_good("marry_1", 100, 6);
	carry_good("marry_1", 100, 7);
	carry_good("marry_1", 100, 8);
	carry_good("marry_1", 100, 9);
	carry_good("marry_1", 100, 10);
	carry_good("marry_1", 100, 11);
	carry_good("marry_1", 100, 12);
	carry_good("marry_1", 100, 13);
	carry_good("marry_1", 100, 14);
	carry_good("marry_1", 100, 15);

	carry_object("cloth")->wear();
	set("no_talk",1);
	set("no_huan",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	AddMenuItem("���", "$0getinfo $1", me);
	AddMenuItem("���", "$0askquest $1", me);
	SendMenu(me);
	return 1;
}
virtual int handle_action(char *comm, CChar *me, char * arg)
{
		if(strcmp(comm, "getinfo") == 0)
			return do_gi(me);
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);

		if(strcmp(comm, "report") == 0)
			return do_r(me);
		if(strcmp(comm, "fail") == 0)
			return 1;

	return CVendor::handle_action(comm, me, arg);

}

int do_gi(CChar * me)
{

		if (me->query("couple_betray") > 1)
		{
			say("�̣£�̾������Ǹ�����Ѿ��޷��ٻ��ˡ�", me);
			SendMenu(me);
			return 1;
		}

		if (me->querymap("couple"))
		{
			say("�̣£�Ц�����㲻���Ѿ�������ػ��Ƿ����ġ�", me);
			SendMenu(me);
			return 1;
		}


		say("�̣£�Ц������λ���������ˣ�", me);
		say("�̣£�Ц����ֻ��Ҫ��������ܳ�Ϊ���˾�����һ����������", me);
		SendMenu(me);
		return 1;
}

int do_aq(CChar * me)
{
		if (!me->querymap("couple") && me->query("couple_betray"))
		{
			say("�̣£�̾�������Ѿ�����ˡ�", me);
			SendMenu(me);
			return 1;
		}

		if (!me->querymap("couple"))
		{
			say("�̣£�Ц�����㻹û�н���أ���������ˣ�", me);
			SendMenu(me);
			return 1;
		}

		CUser * targetx;
		char idd[255];
		snprintf(idd,255,"%s",me->querystr("couple/id"));
		targetx=find_online(idd);

		if (!targetx)
		{
			say("�̣£�̾������İ������ڲ������ϣ������̰ɡ�", me);
			SendMenu(me);
			return 1;
		}

		say("�̣£�̾�˿�������һ�ԡ�����", me);
		say("�̣£ε����������ˣ�����һ�£�����Ҳû�л����ڡ�����", me);
		say("�̣£ε����������֮�����޷��ٸ��飬���������ƾ���Բ��", me);
		say("�̣£ε����������ô��", me);
	AddMenuItem("�Ҿ������¡���", "$0report $1", me);
	AddMenuItem("�����ٿ��ǿ��ǰɡ�", "$0fail $1", me);
		SendMenu(me);
		return 1;
}

int do_r(CChar * me)
{
		CUser * targetx;
		char idd[255];
		snprintf(idd,255,"%s",me->querystr("couple/id"));
		targetx=find_online(idd);

		if (!targetx)
		{
			say("�̣£�̾������İ������ڲ������ϣ������̰ɡ�", me);
			SendMenu(me);
			return 1;
		}

		
		say("�̣£�̾�������»��ճ��ұ���һ�뽭�����´ߡ���", me);
		say("�̣£�̾�������պ��ս���ڣ���ʤ����һ����", me);
		say("�̣£�̾����Ե��Եɢ�������춨��������", me);

		command("chat ���»��ճ��ұ���һ�뽭�����´ߡ���");
		command("chat ���պ��ս���ڣ���ʤ����һ����");
		command("chat Ե��Եɢ�������춨��������");
		g_Channel.do_channel(me, NULL, "chat", "\n\n$HIW���»��ճ��ұ���һ�뽭�����´ߣ�\n���պ��ս���ڣ���ʤ����һ����\nԵ��Եɢ�������춨����ǿ������������\n\n\n");

		char msg[255];
		g_Channel.do_channel(&g_Channel, 0, "news", 
				snprintf(msg, 255, "%s��%sԵ�־��ڽ��գ�����������֣��Ӵ�%s��%s֮�䣬���޹ϸ𡣡���" ,me->querystr("name"),targetx->querystr("name"),me->querystr("name"),targetx->querystr("name") ) );


/*
		me->set("couple/id", "block");
		me->set("couple/name", "�����");
		me->set("couple/gender", "��");
*/
		me->set("last_couple_name",me->querystr("couple/name"));
		me->set("last_couple_id",me->querystr("couple/id"));

		targetx->set("last_couple_name",targetx->querystr("couple/name"));
		targetx->set("last_couple_id",targetx->querystr("couple/id"));

		me->del("couple");
		(CChar *)me->add("couple_betray",1);
		targetx->del("couple");
		(CChar *)targetx->add("couple_betray",1);

		SendMenu(me);
		return 1;
}


virtual int accept_object(CChar * who, CContainer * ob)
{

		if (who->query("couple_betray") > 1)
		{
			say("�̣£�̾������Ǹ�����Ѿ��޷��ٻ��ˡ�", who);
			SendMenu(who);
			return 0;
		}

		if (who->querymap("couple"))
		{
			say("�̣£�Ц�����㲻���Ѿ�������ػ��Ƿ����ġ�", who);
			SendMenu(who);
			return 0;
		}


	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")>=500000 )
	{
		destruct(ob);
		message_vision("ֻ���̣£�΢΢һЦ������$Nһ��ʲô������",who);
		ob=load_item("tongxinyin");
		ob->move(who);
		return 1;
	}

return 0;
}

VENDOR_END;