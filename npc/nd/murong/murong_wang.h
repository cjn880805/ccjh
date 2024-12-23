// wang.c ������
//sound 2001-07-16

NPC_BEGIN(CNmurong_wang);

virtual void create()
{
	set_name("������", "wang furen");
	set("gender", "Ů��");
	set("rank_info/respect", "����");
	set("title","��٢��ɽׯ��");
	set("long", "��������٢��ɽׯ�����ˣ�������ȥ������ʮ�мӣ��������ȴ档");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 0l);
	set("str", 20);
	set("int", 22);
	set("con", 28);
	set("per", 30);
	set("dex", 23);
	set("icon",young_woman1);
	
	set("max_hp", 1500);
	set("hp", 1500);
	set("mp", 1000);
	set("max_mp", 1500);
	set("mp_factor", 0l);
	set("combat_exp", 80000);
	set("score", 15000);
	
	set_skill("shenyuan_gong", 70);
	set_skill("dodge",70);
	set_skill("force", 70);
	set_skill("shenyuan_gong", 70);
	set_skill("yanling_shenfa", 70);
	set_skill("parry", 70);
	set_skill("literate", 70);
	set_skill("strike", 65);
	map_skill("force", "shenyuan_gong");
	map_skill("dodge", "yanling_shenfa");
	set("no_talk",1);
	
	carry_object("shoe")->wear();
//	carry_object("red_silk")->wear();
	carry_object("skirt")->wear();
	set("no_huan",1);
/*
	set_inquiry("����", "�Ҿ�����٢��ɽׯ�����ˣ��������ѵ�û��ʲô��ʾ��");
	set_inquiry("����", "��������٢��ɽׯ��ׯԺ֮���ڣ��˴���Ϊ�ƽ�¥��");
	set_inquiry("����",  "������Ǳ���Ľ�ݲ����������ˡ�");
	set_inquiry("������",  "�������ҵı���Ů������ɱ�����������⡣");
	set_inquiry("Ľ���ظ�",  "Ľ���ظ������ǲ�������ֶ�����������Ա�֮����ʩ����ľ��������𽭺���");
	set_inquiry("������", "������������٢��ɽׯ�Ĳ���֮����һ�����Ǳ����ȥ�ˡ�");
	set_inquiry("��٢��ɽׯ", "���������٢��ɽׯ���Ҿ�����������ˡ�");
	set_inquiry("��ʩˮ��", "���������������֮���ڣ�������ʩˮ��Ĳ����������Ƕ�Ķ�ѽ��");	
*/
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting() && me->query_temp("xy/renwu1_1") && !me->query_temp("xy/renwu1_11")) 
	{
		tell_object(me,"\n��������ϧ�ؿ���һ��$HIC����װ�ع���$COM��������ǧ�������Ӵ���Ū�����ϼѲ軨��ֻ������ȴ�ѽ������㡣");
		tell_object(me,"����������ŭ�ݵض������˺ȵ�����������Щ�����õĶ���������Ū������軨���Ұ�����ȫ�����������ʣ���");
		tell_object(me,"�������������������̾��һ����������������Ҫ�����նε�С���ھͺ���... ...��\n");
		me->set_temp("xy/renwu1_11",1);//���������ֳ���װ�ع�
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		if(me->query_temp("xy/renwu1_1") && !me->query_temp("xy/renwu1_8") )
		{
			AddMenuItem("����������̹��ڸ��ص�����", "fudi",me);
			if(me->query_temp("xy/renwu1_12") && !me->query_temp("xy/renwu1_71"))
				AddMenuItem("���ֺò軨Ϊ��������", "tiaojian",me);	
		}
		AddMenuItem("����������̹������ֵ�����", "name",me);
		AddMenuItem("����������̹������������", "zheli",me);
		AddMenuItem("����������̹��ڴ��ŵ�����",  "chuanwen",me);
		AddMenuItem("����������̹��������������",  "yutian",me);
		AddMenuItem("����������̹���Ľ���ظ�������",  "murong",me);
		AddMenuItem("����������̹��������񶴵�����", "yudong",me);
		AddMenuItem("����������̹�����٢��ɽׯ������", "shanzhuang",me);
		AddMenuItem("����������̹��ڻ�ʩˮ�������", "shueige",me);	
	}
	else if(!strcmp(ask, "name") )
	{
		say("�Ҿ�����٢��ɽׯ�����ˣ��������ѵ�û��ʲô��ʾ��",me);
	}
	else if(!strcmp(ask, "zheli") )
	{
		say("��������٢��ɽׯ��ׯԺ֮���ڣ��˴���Ϊ�ƽ�¥��",me);
	}
	else if(!strcmp(ask, "chuanwen") )
	{
		say("������Ǳ���Ľ�ݲ����������ˡ�",me);
	}
	else if(!strcmp(ask, "yutian") )
	{
		say("�������ҵı���Ů������ɱ�����������⡣",me);
	}
	else if(!strcmp(ask, "murong") )
	{
		say("Ľ���ظ������ǲ�������ֶ�����������Ա�֮����ʩ����ľ��������𽭺���",me);
	}
	else if(!strcmp(ask, "yudong") )
	{
		say("������������٢��ɽׯ�Ĳ���֮����һ�����Ǳ����ȥ�ˡ�",me);
	}
	else if(!strcmp(ask, "shanzhuang") )
	{
		say("���������٢��ɽׯ���Ҿ�����������ˡ�",me);
	}
	else if(!strcmp(ask, "shueige") )
	{
		say("���������������֮���ڣ�������ʩˮ��Ĳ����������Ƕ�Ķ�ѽ��",me);
	}
	else if(!strcmp(ask, "fudi")  && me->query_temp("xy/renwu1_1"))
	{
		if(me->query_temp("xy/renwu1_71"))
		{
			say("���������ĵĵ������ҼҸ��ؾ��ڴ���ǽ�����������Ҫ������컯�Ͳ�����...��",me);
			say("�鼱֮�£�������Щ��֮�⣺�����ⲻ����ǲ�����ţ����ù���������Ҳ�����ڳݣ���",me);
			say("�������Ȼ��������ϼ���������ˣ��������ޱ̾�ǰ���辡�һ���δ����ֱ����������졣���Ծ��ڴˣ���˵���棬�㻹�����ɡ���",me);
			if(me->query_temp("xy/renwu1_11"))
				me->delete_temp("xy/renwu1_11");
			if(!me->query_temp("xy/renwu1_8"))
				me->set_temp("xy/renwu1_8",1);//����ң�ֺͿ���ˮ�Ի�����ȡʯ��¶����Ϣ
		}
		else
		{
			say("������ŭ�����������Ҽ���֮�ܣ���������������֪����",me);
			if(!me->query_temp("xy/renwu1_12"))
				me->set_temp("xy/renwu1_12",1);//ѯ�ʸ�����ܾ�����Ӧ�ֻ���ȡ
		}
	}
	
	else if(!strcmp(ask, "tiaojian") && me->query_temp("xy/renwu1_1") )
	{
		if(me->query_temp("xy/renwu1_11"))
		{
			say("�����˳���Ƭ�̣����������������ֺ��⡰��װ�ع���������Ȼ������㸣�غ��ڣ���",me);
			if(!me->query_temp("xy/renwu1_2"))
				me->set_temp("xy/renwu1_2",1);//����֡���װ�ع���������
		}
	}
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "��װ�ع�") && EQUALSTR(ob->querystr("id"), "hong zhuang")
		&& me->query_temp("xy/renwu1_7") && !me->query_temp("xy/renwu1_71") )
	{
		destruct(ob);
		tell_object(me,"��������һ�����������еĺ�װ�ع�����̾���ѡ�");
		me->set_temp("xy/renwu1_71",1);//����֡���װ�ع���������
		return 1;
	}
	return 0;
}

NPC_END;