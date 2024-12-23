//longnv.h
//code by zwb
//12-23

ZUSHI_BEGIN(CNGuMu_longnv);

virtual void create()
{
	set_name("����","long er");
	
	set("gender", "Ů��");
	set("age", 18);
	set("long","һ���崿��������Ů����������һ�㡣ʵ��������������¡������ݡ�");
	set("attitude", "friendly");
	set("icon", young_woman1);
	
	set("per", 30);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);
	set("foolid",59);	
	set("chat_chance_combat", 9);
	
	set("chat_chance", 20);
	
	set("hp", 9500);
	set("max_hp", 10500);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	
	set("combat_exp", 1500000);
	
	set_skill("force", 250);
	set_skill("yunv_xinfa", 250);    //��Ů�ķ�
	set_skill("yunv_xinjing", 280);	 //��Ů�ľ�
	set_skill("yinsuo_jinling", 200);	//��������
	set_skill("sword", 250);
	set_skill("whip", 230);
	set_skill("yunv_jian", 250);     //��Ů��
	set_skill("quanzhen_jian",140);  //ȫ�潣
	set_skill("dodge", 260);
	set_skill("yunv_shenfa", 260);   //��Ů��
	set_skill("parry", 180);
	set_skill("hubo", 180);          //˫�ֻ���
	set_skill("unarmed",220);
	set_skill("meinv_quan", 220);    //��Ůȭ��
	set_skill("literate",220);
	set_skill("qufeng",350);         //����֮��
	set_skill("tianluo_diwang", 250);
	
	map_skill("force", "yunv_xinjing");
	map_skill("sword", "yunv_jian");
	map_skill("dodge", "yunv_shenfa");
	map_skill("parry", "meinv_quan");
	map_skill("unarmed", "meinv_quan");
	
	create_family("��Ĺ��", 3, "����");
	
	set("book_count", 1);
	set("count",1);
	set_temp("have_zhen", 5);
	set_temp("have_suo", 1);
	
	set_inquiry("����",ask_me);
	set_inquiry("��Ů����","��Ů������ȫ�潣���ϱڣ������޵У�");
	set_inquiry("��Ĺ��","�ҵ�����ʦ���ű�����������ʦ��һ����ˣ�����...");
	set_inquiry("��Ů�ľ�",ask_yunv);
	set_inquiry("�����",ask_zhen);
	set_inquiry("������", ask_suo);
	
	set("env/wimpy", 40);
	
	carry_object("shunvjian")->wield();
	carry_object("baipao")->wear();
	set("no_huan",1);
}

virtual char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		perform_action("sword he", 1);
		break;
	case 2:
		perform_action("unarmed you", 1);
		break;
	case 3:
		perform_action("force roar", 1);
		break;
	}
	return "";
}

virtual char * chat_msg(CChar * player)
{
	switch(random(3))
	{
	case 0:
		return "�����Ǹ����ı��ҵ��ˣ��ҵ���ʵ�ڿ�������";
	case 1:
		return "��Ů����ȫ�潣�ϱڣ��ǿ������޵С������Ǹ����Ѿ������ˡ���";
	case 2:
		return "���������̾�˿�����ת��ͷȥ��";
	}
	return "";
}

virtual void attempt_apprentice(CChar  * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "��Ĺ��"))
	{
		say(" �Բ����Ҳ������˴򽻵���",player);
		SendMenu(player);
		return;
	}
	if(EQUALSTR(player->querystr("class"), "taoist"))
	{
		say(" ������ʦ�����ˣ������Ҹ�ʲô��",player);
		SendMenu(player);
		return;
	}
	if(player->query("repute") < 50000)
	{
		say(" ��Ĺ������ʦ��һ���͹��ˣ��ҿɲ��������˰ܻ���Ĺ������",player);
		SendMenu(player);
		return;
	}
	if(player->query_dex() < 30)
	{
		say(" ����ô��׾ѧ�����ҹ�Ĺ�Ĺ���",player);
		SendMenu(player);
		return;
	}
	if(player->query_int() < 40)
	{
		say(" ������ô���ĵ��ӣ�һ�����������Ѫ�ģ���Ҫ��Ҫ��",player);
		SendMenu(player);
		return;
	}
	if(player->query_skill("yunv_xinfa", 1) < 100)
	{
		say(" ��Ա����ķ�����ʶ��ǳ����ȥ������������ѧѧ�ɡ�",player);
		SendMenu(player);
		return;
	}
	if(player->query_skill("tianluo_diwang", 1) < 100)
	{
		say(" ������޵����Ƶ���ʶ��ǳ����ȥ������������ѧѧ�ɡ�",player);
		SendMenu(player);
		return;
	}
	if(player->query("max_mp") < 1000)
	{
		say(" ���������Ϊ��ǳ��ѧ������ô����Ĺ���",player);
		SendMenu(player);
		return;
	}
	
	else
	{
		say(" �ðɣ��Ҿ����������ͽ���ˡ�");
		recruit_apprentice(player);
	}
}


static char * ask_yunv(CNpc * npc , CChar * player)
{
	CContainer * ob;
	static char msg[255];
	
	if(DIFFERSTR(player->querystr("family/family_name"), "��Ĺ��"))
		return snprintf(msg,255,"%s�뱾�ɺ��޹ϸ𣬺��������ɵ��ľ���",player->name());
	
	if(EQUALSTR(player->querystr("class"), "taoist"))
		return "Ц���������Ź֡�";
	
	if (npc->query("book_count") < 1)
		return "�������ˣ����ɵ���Ů�ľ��Ѿ�����ȡ���ˡ�";
	
	npc->add("book_count", -1);
	ob = load_item("yunvjing1");
	ob->move(player);
	return "�ðɣ��Ȿ����Ů�ľ������û�ȥ�ú��ж���";
}

static char * ask_me(CNpc * npc , CChar * player)
{	
	CContainer  * obj;
	
    if(npc->query("count") < 1)
		return "��֪�����������䣿�ղ��Ѿ����˸������ˣ�лл�㡣";
	
	player->set_temp("marks/ask_long", 1);
    npc->add("count", -1);
    obj=load_item("junzijian");
    obj->move(player);
    return "������ӽ��͸��������������������ʱ���뽻������";
}

static char * ask_zhen(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "��Ĺ��"))
		return "�㲻���ҹ�Ĺ�ɵĵ��ӣ����ܸ��㡣";	
	if(EQUALSTR(player->querystr("class"), "taoist"))
		return "������ʦ��Ҫ��������ȥ�ɣ������ɲ��ܸ��㡣";
	if(player->query_temp("mark/get_yufeng_zhen"))
		return "�㲻�Ǹ��ù��𣿲�Ҫ��ô̰�ĺò��ã�";
	if(npc->query("have_zhen") < 0)
		return "�������ˣ�������Ѹ���������ͬ���ˡ�";
	
	load_item("yufeng_zhen")->move(player);
	
	player->set_temp("mark/get_yufeng_zhen",1);
	npc->add_temp("have_zhen", -1);
	
	message_vision("��������$Nһ������롣", player);
	return "";
}

static char * ask_suo(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "��Ĺ��"))
		return "�㲻���ҹ�Ĺ�ɵĵ��ӣ����ܸ��㡣";		
	if(EQUALSTR(player->querystr("class"), "taoist"))
		return "��ѧ�Ĳ���������������Ҫ��������ʲô��";
	if(npc->query_temp("have_suo") != 1)
		return "�������ˣ��������Ѹ���������ͬ���ˡ�";
	
	load_item("ring_whip")->move(player);
	
	npc->delete_temp("have_suo");
	
	message_vision("��������$Nһ����������", player);
	return "";
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if (EQUALSTR(me->querystr("family/family_name"), "��Ĺ��")) return 0;
	
	me->add_temp("tmark/��", -1);
	
    if(! me->query_temp("tmark/��"))
	{
        say("����̾�˿����������㣬˵�������ǵ�Ե���Ѿ�����,��Ҳûʲô�����ɽ������,�����ټ��ɡ�", me);
		SendMenu(me);
		
		DownLoad(me);
		return 1;
	}
	
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
	if(me->query_temp("tmark/��"))
        return 1;
	
	return 0;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "��Ĺ����" ))
		return notify_fail("�����������");
	char msg[255];
	int exp;
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s���˵�ͷ�����������͹����İ�����",name(1)));
		tell_object(who, "\n$YEL��������渣���ھ�Ѻ�˰��ڵ�����");
		tell_object(who, snprintf(msg, 255, "$YEL�����%d�ľ��齱������������������%d��",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)ѹ�˰��ڳɹ��������%d�ľ��齱������������������%d�㣡", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	else if(EQUALSTR(ob->querystr("id"), "jue qing dan")&& who->query_temp("gumu/jq_dan_nv") && !who->query("gumu/���"))
	{
		say("������������");
		say("���̫��л���ˣ������ҵ�һ�����⣬�����¡�");
		who->set("gumu/���",1);
		SendMenu(who);
		destruct(ob);
		g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s����%s(%s)$HIY�´�����ȣ���ܹ���ָ�������һؾ��鵤��$COM",  who->querystr("family/family_name"),who->name(1),who->id(1)));
		exp=who->query("age")*who->query("level");
		if(exp<3000)
			exp=2000+random(3000);
		int repute=random(int(exp/2))+exp;
		if(who->query("repute")<0)
			repute=-repute;
		who->add("repute",repute);
		who->set("xkd/gumu",1);
		if(DIFFERSTR(who->querystr("family/family_name"), "��Ĺ��"))
		{
			who->add("combat_exp",exp);
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s���$HIY%d$HIC��������齱����ͬʱ�����%d��Ľ���������\n\n$COM",who->name(1), exp,repute));
			message_vision (snprintf(msg, 255, "$HIR$N�����%d�������齱����ͬʱ�����%d��Ľ���������",exp,repute),who);
		}
		else
		{
			CContainer * bot = load_item("skybook");
			bot->move(who);
			who->add("combat_exp",exp);
			message_vision (snprintf(msg, 255, "$HIR$N�����%d�������齱����ͬʱ�����%d��Ľ�������",exp,repute),who);
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s���$HIY%d$HIC��������齱����һ��$HIY���������顱��ͬʱ�����%d��Ľ���������\n\n$COM",  who->name(1),exp,repute));
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)������������顣", who->name(1),who->id(1)));
		}
		who->delete_temp("gumu/jq_dan_nv");
		who->set("gumu/jq",who->query("age"));
		return 1;
	}
	else if (EQUALSTR(ob->querystr("id"), "skybook")&& who->query("gumu/jq")==who->query("age") && EQUALSTR(who->querystr("family/family_name"), "��Ĺ��"))
	{
		destruct(ob);
		say("�㲻��Ҫ�����",who);
		say("�Ǻðɣ��Ҹ�����һ�����ܡ�",who);
		say("�ǹ�����ʦ���ŵ����ܡ�",who);
		say("��ʦ��������ס��һ�����徻�ĵط���",who);
		say("������к��ĵĻ�������Ǳˮ��ȥ�ҵ�����",who);
		who->set_temp("gumu/lin",1);
		SendMenu(who);
		return 1;
	}
	else
		return 0;
}


ZUSHI_END;




