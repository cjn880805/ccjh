// pub_clothboss.h �ϰ���
// code by Fisho

VENDOR_BEGIN(CNpub_clothboss);

virtual void create()
{
	set_name("�ϰ���","pub_clothboss");

	set("icon", young_woman12);
	set("title", "��������");
	set("gender", "Ů��" );
	set("age", 22);
	set("combat_exp", 6000);
	set("str", 100);
	set("dex", 100);
	set("con", 100);
	set("int", 100);
	set("per", 40);
	set_skill("sword", 100);
	set_skill("dodge", 600);
    set_skill("doggiesteps", 400);
	map_skill("dodge","doggiesteps");

	set("shen_type", 1);
	set("attitude", "friendly");
	add_money(5000);
	carry_object("dress")->Do_Action(DO_WIELD);
	carry_object("abab_sword")->Do_Action(DO_WIELD);

	carry_good("rover", 10);
	carry_good("female3_cloth", 10);
	carry_good("female4_cloth", 10);
	carry_good("female5_cloth", 10);
	carry_good("female6_cloth", 10);
	carry_good("female7_cloth", 10);
	carry_good("male4_cloth", 10);
	carry_good("male5_cloth", 10);
	carry_good("male7_cloth", 10);
	carry_good("male8_cloth", 10);
	carry_good("yan_dress", 10);
	carry_good("zi_dress", 10);
	carry_good("xiu_scarf", 10);
	carry_good("xiu_cloth", 10);
	carry_good("sha_dress", 10);
	carry_good("scarf", 10);
	carry_good("qi_dress", 10);
	carry_good("moon_dress", 10);
	carry_good("pink_dress", 10);
	carry_good("marry_dress", 10);
	carry_good("liu_dress", 10);
	carry_good("jade_belt", 10);
	carry_good("hat", 10);
	carry_good("gui_dress", 10);
	carry_good("guazi", 10);
	carry_good("fu_cloth", 10);
	carry_good("doupeng2", 10);
	carry_good("cuiyu", 10);
	carry_good("color_dress", 10);
	carry_good("cheng_cloth", 10);
	carry_good("belt", 10);
	carry_good("shuikao", 10);
	carry_good("zhanyi", 10);
	set("no_talk",1);


//	set_inquiry("��·", "????", "����·��ô�ߣ�");
//	set_inquiry("����", "�����ҵ����֡�");

};
//��NPC�Ľ���ϵͳ����Ҫ������һЩ�򵥵�����
virtual int do_talk(CChar * me, char * ask = NULL)
{
	int mask;
	if(! me || ! ask) return 0;
	mask = me->query_temp("mark/�ϰ���");
	//now we handle the player's answer
	if (EQUALSTR(me->querystr("gender"), "Ů��"))
	{
		tell_object(me,"������ɣ�����������кܶ�Ư�����·�Ьñ��");
		return 0;
	}
	if(mask == 1)	//has questioned
	{
		if(strcmp(ask, "ihear") == 0)	//player selected the answer 1
		{
			say("���������Һ��𡭡�˧�磨^_^����", me);
			AddMenuItem("�����ʲô�ô���", "do3", me);
			AddMenuItem("��̫æ���ұ��˰���ɡ�", "", me);
			//set mark
			me->set_temp("mark/�ϰ���", 2);
			SendMenu(me);
			return 1;
		}
	}

	if(mask == 2)	//has questioned 2 times
	{
		if(strcmp(ask, "do3") == 0)	
		{				
			say("�Ǿ�50����ô����", me);
			AddMenuItem("�ðɣ����ڽ�ķ��ϡ���", "do50", me);
			AddMenuItem("ȥȥȥ����ô��Ǯ˭����ɣ�", "", me);
			//set mark
			me->set_temp("mark/�ϰ���", 3);
			SendMenu(me);
			return 1;
		}
	}

	//if mask > 100, it stand for the price of discuss
	if(mask >= 3)
	{
		if(mask == 3 && strcmp(ask, "do50") == 0)
		{
			say("����һ�Σ����𡭡�", me);
			AddMenuItem("��ѽ���������ȸ��㲹��Ѱɣ�", "yes", me);
			AddMenuItem("�´���˵�ɣ�", "", me);
			me->set_temp("mark/�ϰ���", 50);
			me->add("mp", -10);
			me->add("hp",-100);
			SendMenu(me);
		//	me->UpdateMe ();
			return 1;
		}
		if(strcmp(ask, "yes") == 0)
		{
			if ( me->query("hp")<1)
			{
				char msg[255];
				snprintf(msg, 255, "%s���ڲ��͹��ȣ����ھ��������ˡ�", me->name());
				MessageVision(me, "chat", msg);
				return 1;
			}
			me->add("combat_exp", 1);
			char msg[255];
			snprintf(msg, 255, "��������һ��ɵ��%s���� 5 �㾭�飬ͬʱ����%d������ɵ����ɵ����", me->name(), mask);
			MessageVision(me, "chat", msg);
			CMoney::Pay_Player(me, mask);
			me->set_temp("mark/�ϰ���", 0l);
			return 1;
		}
	}

//	if(mask == -1)
//	{
		//default
		//set the npc questions
		say("�������Դ����๫����֮��������˯���ú���ѽ������������û�пգ�", me);
		//set my answer 1
		AddMenuItem("�٣������ҳ���˯����������һ�ɲ��ɡ�", "ihear", me);
		//set my answer 2
		AddMenuItem("������˼����û�ա�", "", me);
		//set mark
		me->set_temp("mark/�ϰ���", 1);
		//must have this state, to send the questions to client
		SendMenu(me);
		return 1;
//	}
//	me->set_temp("mark/�ϰ���", -1);
//	return 1;
//	return CNpc::do_talk(me, ask);
}

VENDOR_END;
