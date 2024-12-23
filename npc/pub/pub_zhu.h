// pub_zhu.c ����

// code by Fisho
// date:2000-12-17
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_zhu);

virtual void create()
{
	set_name("����","zhu xi");

	set("icon", old_man2);
	set("long","����������Ϊ������һ����ѧ�ң��������īˮ�Ⱥ���Ҫ�");
	set("gender", "����");
	set("age", 65);
	set("no_get", 1);
	set_skill("literate", 300);
	
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	
	set("combat_exp", 400000);
	set("shen_type", 1);
	set("chat_chance", 3);

	set_inquiry("ѧλ",ask_degree);
	set_inquiry("����",ask_buy);
	set_inquiry("��","��!�鵽��ʱ�����١�");
	set_inquiry("����" ,"�裿�㲻���ҵ��������㣿��!");

	carry_good("lbook1",500);
	carry_good("lbook2",500);
	carry_good("lbook3",500);
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch (random(4))
	{
	case 0:
		return "����˵��������֮�£�Ī������������֮����Ī��������";
	case 1:
		return "����˵���������ˣ�С�������ɣ����������δ������֮��";
	case 2:
		return "����˵������ѧ֮�����������¡���������ֹ�����ơ� ";
	case 3:
		return "����˵����������֪���������ģ�������ң��ι�ƽ���¡�";
	}
	return "";
}

virtual int handle_action(char *comm, CChar *me, char *arg)
{
	if(is_fighting()) return 0;
	
	if(strcmp(comm, "buy") == 0 && me->query_skill("literate", 1) < 21)
		return notify_fail("���䲻�������㡣");
	if(strcmp(comm, "sell") == 0)
		return notify_fail("����Ц�������������������Լ����Űɡ�");

	return CVendor::handle_action(comm, me, arg);
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(DIFFERSTR(arg, "literate")) return 1;

	me->add_temp("mark/��3", -1);
	if(! me->query_temp("mark/��3"))
	{
		DownLoad(me);
		return 1;
	}
	
	return 0;
}

int recognize_apprentice(CChar * ob)
{
	if (! ob->query_temp("mark/��3"))
		return 0;

	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 1000) 
	{
		message_vision("����ͬ��ָ��$NһЩ����д�ֵ����⡣", who);
		who->add_temp("mark/��3", ob->query("value") / 1000);
		DownLoad(who);
        if( who->query_skill("literate", 1) > 21)
		{
			say("����������һ�����Ļ�֪ʶ,Ҳ�����Լ����������ˡ�", who);
			SendMenu(who);
			destruct(ob);
			return 1;
		}
	}
	destruct(ob);
	return 1;
}

static char * ask_buy(CNpc *ob,CChar *me)
{
	return "������в��ٶ����˱ض�����Ӵ!";
}

static char * ask_degree(CNpc *who,CChar *ob)
{
	int lv;
	static char msg[255];
	static char degree_desc[][12] = {
		{"��ä"      ,},
		{"ͯ��"      ,},
		{"���"      ,},
		{"����"      ,},
		{"��Ԫ"      ,},
		{"��ʿ"      ,},
		{"��Ԫ"      ,},
		{"��ʿ"      ,},
		{"̽��"      ,},
		{"����"      ,},
		{"״Ԫ"      ,},
		{"����Ժʿ"  ,},
        {"����˶ʿ"  ,},
		{"���ֲ�ʿ"  ,},
		{"����Ժ����",},
		{"����ʿ"    ,},
		{"ѧʿ"      ,},
		{"�ڸ��ѧʿ",},
        {"�ڸ��׸�"  ,},
		{"��ѧ����ʦ",},
		{"ʥ��"      ,},
	};
	
	lv = (ob->query_skill("literate") / 5);
	if(lv > 20) lv = 20;
	
	if (lv < 3) 
	{
		ob->set("degree",degree_desc[lv]);
		return snprintf(msg,255,"%s�����ǵ�īˮҲ����˼��? �������ѧλ������! ",ob->name() );
	}

	if (lv < 10) 
	{
		ob->set("degree",degree_desc[lv]);
		return snprintf(msg,255,"%s������������ǰ;���ܸ�������ѧλ���㣬�����ú�Ŭ��! ",ob->name() );
	}
	

	ob->set("degree",degree_desc[lv]);
	return snprintf(msg,255,"��Ȼ�ǳ���������ǰ�˰���%s���ҷǳ��������л���Ϊ����ѧλ! ",ob->name());
}

VENDOR_END;