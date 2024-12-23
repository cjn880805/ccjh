//ouyangke.h
//Lanwood 2000-01-05

NPC_BEGIN(CNbtshan_ouyangke);

virtual void create()
{
	set_name("����ׯ��", "ouyang ke");
	set("long", "��һ��Ʈ�ݵİ�ɫ��������ҡ���ȣ��������š�");
	set("title", "����ɽ��ׯ��");
	set("nickname", "������");
	set("gender", "����");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("icon", young_man3);
        set("per", 30);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("hp", 6500);
	set("max_hp", 6500);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 10);

	set("combat_exp", 400000);
	set("score", 40000);
        set_inquiry("�ض�","�Ҷ��������ĵģ����������Ǿ����Ҳ������Σ�����ʵҲ�ֲ�������");
        set_inquiry("����ׯ��","�Ҹ��׶��������ܴ󣬵���������Ҳ��Ṽ�����ˣ��Ҳ��һ�ȥ������");
	set_skill("unarmed", 100);
	set_skill("hand", 100);
	set_skill("dodge", 120);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("staff", 100);
	set_skill("hamagong",100);
	set_skill("xunshou_shu",100);
	set_skill("chanchu_bufa", 100);
	set_skill("shexing_diaoshou", 110);
	set_skill("lingshe_zhangfa", 110);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");
	carry_object("zheshan", 1);
	carry_object("yaoqin", 1);

	//set("startroom","/d/city/beidajie1");

    create_family("����ɽ��",2,"����");

	set("chat_chance", 10);
	
	carry_object("baipao")->wear();
	add_money(1000);
	set("no_huan",1);
};

virtual char * chat_msg()
{
	switch(random(4))
	{
	case 0:
		return "����ׯ������: �������Ѻδ�����������������¡�����";
	case 1:
		return "����ׯ�������ؿ��Žֱߵ�Ů�����ǡ�";
	case 2:
		return "����ׯ����ֽ��һչ��ת����ȥ������̾�����ս�����һ���壬�˼�δ��ʶ����";
	case 3:
		random_move();
		return 0;
	}

	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if(! who) return;

	if ( EQUALSTR(who->querystr("gender"), "Ů��"))
	{
	   switch(random(3))
	   {
		case 0:
			g_Channel.do_emote(me, who, "rose", 0);
			break;
	  	case 1:
			g_Channel.do_emote(me, who, "kiss", 0);
			break;
	   	case 2:
			g_Channel.do_emote(me, who, "love", 0);
			break;
	   }
     
	}
	else
       message_vision(snprintf(msg, 255, "$N����$n̾��һ����˵����λ%s, ��Ҫ��������һ��Ů���Ӿͺ��ˡ�", query_respect(who)), me, who);

	return;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];
	
	if ( EQUALSTR(me->querystr("family/family_name"), "����ɽ��"))
	{
	     if(me->query("combat_exp")<10000)
		 {
	          say("��ľ���̫�ͣ��һ��������㡣����Ŭ���ɡ�", me);
			  SendMenu(me);
		 }
	     else
         {
			say("�������Ҫ�ú�ѧ��");             
			command(snprintf(msg, 80, "recruit %ld", me->object_id()));
         }

		 return;
	}

	if (EQUALSTR(me->querystr("gender"), "Ů��"))
			message_vision(snprintf(msg, 255, "����ׯ�������˵������λ%s�����ҵĺ���֪���������ڻ��������㣬ֻ�������ϰ���ɽ��", query_respect(me)), this);
	else
		message_vision(snprintf(msg, 255, "����ׯ��ЦЦ˵����λ%s�������ڻ��������㣬ֻ�������ϰ���ɽ��", query_respect(me)), this);
     
	tell_object(me, "ֻ������ׯ����ֽ��������ǰһ�Σ�\n�������ǰһ����������ƮƮ�ط��˳�ȥ����");
    me->move(load_room("����ɽ������"));
}

virtual int accept_fight(CChar * me)
{
	char msg[255];

	if (EQUALSTR(me->querystr("gender"), "Ů��"))
	{
		say(snprintf(msg, 255, "����ׯ���ڰ���˵������λ%s���������۸�Ů�����أ�", query_respect(me)), me);
		SendMenu(me);
		return 0;
    }
          
	if (EQUALSTR(me->querystr("family/family_name"), "����ɽ��"))
	{
		if(me->query_combat_exp() < 100000 )
		{
			say("����ׯ��Ц������ľ���̫����,��������ɡ���", me);
			SendMenu(me);
			return 0;
		}
	}
	
	message_vision(snprintf(msg, 255, "����ׯ��һ����˵������λ%s����������ˡ�", query_respect(me)), me);
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{

	if( EQUALSTR(environment()->querystr("base_name"), "��������Ժ"))
		return notify_fail("����ׯ����æ����椣�û�����㡣");

	if( ob->query_temp("����ׯ��"))
	{
		say("����Ѿ�û��˼�ˡ�", who);
		SendMenu(who);
		return 0;
	}

	if(query("sum") > 10)
	{
		say("�ҽ���̫���ˣ�������˵�ɡ�", who);
		SendMenu(who);
		return 0;
	}

	if ( DIFFERSTR(ob->querystr("gender"), "Ů��"))
	{	
		return notify_fail("����ׯ������Ҫ���������");
	}
	
	if ( ob->query("age") <18 )
	{	
		say("����ׯ��ҡҡͷ�����Ҳ�����ʲô���ˣ���������δ���꣬�һ����²����֡�", who); 
		SendMenu(who);
		return 0;
	}
    
	if ( ob->query("age") >40 )
	{	 
		say("����ׯ��΢΢�ؿ�Ц�����Ҳ���������λ������ڲ�����", who);
		SendMenu(who);
		return 0;
	}

	int per = ob->query("per");
	if( per < 18)
	{
		say("����Ȼ��ɫ�������ǻ�ѡ��Ů���ģ�", who);
		SendMenu(who);
		return 0;
	}
	
	ob->set_temp("����ׯ��", 1);

	add("sum", 1);
	if(query("sum") > 10)
	{
		remove_call_out(do_reset);
		call_out(do_reset, 900);
	}

	CMoney::Pay_Player(who, 80 * per);
	 
    message_vision("����ׯ��һ�Ѱ�$n���ڻ����$N˵����������������ѣ��ۻ�ͷ����\n˵�꣬��Я��$n������Ժ��ȥ...", who, ob);
    move(load_room("��������Ժ"));
    return 1;
}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->del("sum");
}

NPC_END;
