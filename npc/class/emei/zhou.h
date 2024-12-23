//zhou.h
//Lanwood 2000-01-05

NPC_BEGIN(CNemei_zhou);

virtual void create()
{
	set_name("�ܲ�ޱ", "zhou caiwei");
	set("long", "һ�����������ס�����һ�������ѡ������������Ц�д���Щ�����Ρ�");
	set("icon", young_woman2);
	
	set("gender", "Ů��");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	
	set_inquiry("���", "������ȣ����԰ɡ�");
	set_inquiry("����", "Ҫ�������ҵ�ʦ����ȥ��");
	set_inquiry("����", "���ġ�����Ҳ���ң�");
    set_inquiry("��ʦ̫", "ʦ���ѵ���ͽ�����Ȱͽ��Ұɡ�");
	set_inquiry("��", "����ô֪����ϲ��������");
	

	set("foolid",14);	

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3500);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 1000);
	
	set("combat_exp", 1500000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("force", 100);
	set_skill("throwing", 100);
	set_skill("dodge", 100);
	set_skill("finger", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("claw", 400);
	set_skill("literate", 100);
	set_skill("mahayana", 100);
	set_skill("jinding_zhang", 100);
	set_skill("jiuyin_zhua", 200);
	set_skill("tiangang_zhi", 100);
	set_skill("huifeng_qijue", 351);
	set_skill("zhutian_bu", 100);
	set_skill("linji_zhuang", 100);
	map_skill("force","linji_zhuang");
	map_skill("claw","jiuyin_zhua");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");

	prepare_skill("claw", "jiuyin_zhua");
	map_skill("sword","huifeng_qijue");
	create_family("������", 4, "���ŵ���");
	
	carry_object("changjian")->wield();
	carry_object("ycloth")->wear();
	set("no_huan",1);
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];
	
    if (me->query("repute")<100)
    {
       g_Channel.do_emote(this, 0, "heng", 0);
       say(snprintf(msg, 255, "%s������ʲô������͵�������ݣ����������ޣ�", me->name()));
       g_Channel.do_emote(this, me, "!!!", 0);
       kill_ob(me);
	   return;
    }
   
   // if ( me->query_temp("marks/�η���") )
    {
		if ( me->query("betrayer") > 1)
		{
			 say(g_Channel.do_emote(this, me, "heng", 1), me);
			 say("�������������Ź棬���Ķ��⡣������������Ϊͽ��", me);
			 SendMenu(me);
			 return;
		}

		if (me->query("per") < 22 )
		{
			say(g_Channel.do_emote(this, 0, "giggle", 1), me);
			say(snprintf(msg, 255, "��λ%s��ò̫Ҳ...������������ذɣ�", query_respect(me)), me);
			SendMenu(me);
			return;
		}

		if (me->query_dex() < 26  || me->query_int() < 28 )
		{
		   say(snprintf(msg, 255, "��λ%s�������ʲ���һ�㡣", query_respect(me)), me);
		   say("�����д���Ǳ���������Ȼ�ȥĥ��ĥ����", me);
		   SendMenu(me);
		   return ;
		}

		if (me->query_skill("linji_zhuang",1)<200)
		{
		   say(snprintf(msg, 255, "��λ%s���Ҷ�ü�ķ��ƺ�����Ĳ�����", query_respect(me)), me);
		   say("�����д���Ǳ���������Ȼ�ȥĥ��ĥ����", me);
		   SendMenu(me);
		}
    
		say("������ô��������Ϊ����������ɡ�");
		command(snprintf(msg, 255, "recruit %ld", me->object_id()));
		me->delete_temp("marks/�η���");
		return;
	} 

    say("��û�¾Ϳ������ˡ�", me);
    SendMenu(me);
    return;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "doggie") || DIFFERSTR(ob->querystr("name"), "����" ))
	{	
		message_vision("$N����ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "Ȫ����", "quanyue pai");

	message_vision("$N���ͷ��͵͵��$nһ�鶫����", this, who);
	ob->move(who);

	return 1;
}


NPC_END;




