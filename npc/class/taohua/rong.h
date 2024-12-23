//rong.h
//Lanwood 2000-01-11

NPC_BEGIN(CNtaohua_rong);

virtual void create()
{
	set_name("�ض�", "huang rong");
    set("title", "�һ�����������Ů");
    set("gender", "Ů��");
    set("age", 18);
    set("long", "�����һ������Ķ���Ů�������ڵ����������������������Ů�������۰������������ѷ��ϲ���Ĵ����ܡ�");
    set("icon",young_woman1);

    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("hp", 800);
    set("max_hp", 2400);
    
    set("mp", 1000);
    set("max_mp", 1000);
    set("mp_factor", 0l);
	
    set("combat_exp", 200000);
    
	
    set_skill("force", 60);
    set_skill("bibo_shengong", 80);
    set_skill("unarmed", 80);
    set_skill("xuanfeng_leg", 80);      // ����ɨҶ��
    set_skill("strike", 80);            // �����Ʒ�
    set_skill("luoying_shenzhang", 80);
    set_skill("dodge", 150);
    set_skill("anying_fuxiang", 100);
    set_skill("parry", 85);
    set_skill("literate",150);           // ����ʶ��
    set_skill("sword", 80);
    set_skill("luoying_shenjian",80);
	
    map_skill("force"  , "bibo_shengong");
    map_skill("unarmed", "xuanfeng_leg");
    map_skill("strike" , "luoying_shenzhang");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("sword"  , "luoying_shenjian") ;
	
    create_family("�һ���", 2, "����");

	set_inquiry("���Ϲ�", "����ѽ, ����������? ");
	set_inquiry("�����", "��ô? �����Ҿ�������Ϣ��? ");
	set_inquiry("��л�", "ʦ�������˼Ҿ�ϲ���Խл���! ");
	set_inquiry("�л���", ask_chicken);
	set_inquiry("����","�������Ϻ��ҵ�������ȥ���ҵ���취Ū�����ǵĶ������С�����");

	set_temp("can_cook", 5);
	
    carry_object("ruanwei")->wear();
    carry_object("shudai")->wear();
	set("no_huan",1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		if (DIFFERSTR(me->querystr("family/family_name"), "�һ���") )			
		{
			remove_call_out(do_saying);
			call_out(do_saying, 2, me->object_id());
		}
	}
}

/*
int do_kiss ( string arg )
{
   if ( (string) ob -> query ("gender") == "����" )
      command ("say ����������������"+ ob->query("name") + "Ҫ�����ң�\n") ;
   else
      message_vision("\n�ض���$NЦ�������ý�㲻Ҫ����������������\n", ob);
   return 1 ;
}
*/

static void do_saying(CContainer * ob, LONG param1, LONG param2)
{
    CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

    if (EQUALSTR(who->querystr("gender"), "����"))
        message_vision("�ض����־���֮ɫ��������$Nһ�ۣ�˵����������ʲô�ˣ������Ҵ��ҵĹ뷿���ٲ�����ȥ��������ô���㣡��", who);
    else
        message_vision("�ض����˿�$N��˵�������þ�û���������ˣ���֪��λ�������Ҿ�������Ϣ��", who);
}

virtual void attempt_apprentice(CChar * me)
{
   if (me->query_temp("marks/�ض�") == 1)
   {
      load_item("ruanwei")->move(me);
      tell_object(me,"�ض�����������һ����⫼׵ݸ��㡣");
      me->set_temp("marks/�ض�",2);

	  say("�ض�һ��Ц�⣺����л����������Ŀ���!��", me);
      say("�ض�����һЦ���Ҳ���ͽ��..��Ҳ�����������������⫼׾��͸���ɣ�", me);	  
   }
   else
		say("�������ôС����ͽ�ܣ��ܲ�����ģ�", me);

   SendMenu(me);
}

static char * ask_chicken(CNpc * npc, CChar * me)
{
	if(me->query_temp("marks/��"))
		return "���������ô��ô������˵����ꤻ���";
	else
	{
		npc->say("�ض�������˵���л������Ǻ��������ز����ҵ�������˺ô�ľ��Ÿ㵽�����������ط�������Ҫ�ľ���һ��Ҫ��Сĸ����", me);
		me->set_temp("marks/��", 1);
		npc->say("����Գ�ȥ�ˡ�", me);
		npc->SendMenu(me);		
	}

	return 0;
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if( EQUALSTR(ob->querystr("id"), "ji") || EQUALSTR(ob->querystr("name"), "Сĸ��") )
	{
		if(this->query_temp("can_cook") > 0)
		{
			message_vision("$N˵��������Խл�����������Ҳ�ܾ�û���ˣ���һֻ����ɡ���", this);
			destruct(ob);
			load_item("jiaohuaji")->move(who);
			this->add_temp("can_cook", -1);
			return 1;
		}
		else
		{
			message_vision("$N˵��������Խл�������̫���ˣ���������˵�ɡ���", this);
			return 0;
		}
	}
	if ( DIFFERSTR(ob->querystr("id"), "damo ling") || DIFFERSTR(ob->querystr("name"), "��Ħ��") )
	{	
		message_vision("$N����ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "������", "qingyue pai");

	message_vision("$N���ͷ��͵͵��$nһ�鶫����", this, who);
	ob->move(who);

	return 1;
}


NPC_END;
