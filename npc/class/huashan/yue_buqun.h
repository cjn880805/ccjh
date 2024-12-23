//yue_buqun.h
//Lanwood 2000-01-08

ZUSHI_BEGIN(CNhuashan_yue_buqun);

virtual void create()
{
	set_name("������",  "yue bufan");
	set("title", "��ɽ������");
	set("nickname", "���ӽ�");
	set("gender", "����");
	set("class", "swordsman");
	set("age", 55);
	set("long",
		"����������ִ�ƻ�ɽ�ɣ��˵���������һ��һ�ĸ��֡�");
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("icon",old_man1);
	
	set("mp", 2400);
	set("max_mp", 2400);
	set("mp_factor", 30);
	set("max_hp",6000);
	
	set("combat_exp", 1000000);
	set("repute", -200000);
//	set("xunshan", 1);
	set("apprentice_available", 3);
	
	set("chat_chance_combat", 20);
	
	set_skill("unarmed", 200);
	set_skill("sword", 220);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("literate", 180);
	set_skill("huashan_shenfa", 200);
	set_skill("huashan_sword", 220);
	set_skill("zixia_shengong", 220);
	set_skill("hunyuan_zhang", 200);
	set_skill("pixie_sword",250);
	set_skill("zhengqijue",200);
	
	map_skill("sword", "pixie_sword");
	map_skill("parry", "pixie_sword");
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "hunyuan_zhang");
	map_skill("dodge", "huashan_shenfa");
	
	create_family("��ɽ��", 13, "����");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	carry_object("zixia_book");
	carry_object("allow_letter");
	
	remove_call_out(do_reset);
	call_out(do_reset, 900, 0);	
	set("no_huan",1);
};

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("force powerup", 0);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

    if( query("apprentice_available") ) 
	{
        if( me->query_int() < 20 )
                say(snprintf(msg, 255, "�һ�ɽ���Խ���Ϊ�������ҿ����ʺ���ѧ������", query_respect(me)), me);
        else 
		{
			say("�ã��ã��ã��ܺá�");
			command(snprintf(msg, 80, "recruit %ld", me->object_id()) );
			
            //me->set("class", "swordsman");
			add("apprentice_availavble", -1);
			return;
        } 
	}
	else
        say("�Ϸ�����Ѿ������������ӣ���������ͽ�ˡ�", me);
      
	SendMenu(me);
}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->set("apprentice_available", 3);
}

/*
virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->querystr("family/family_name") == "��ɽ��")
	{
		ask_for_xunshan(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "xunshan") == 0 && me->query_temp("pending/xunshan"))
	{
		me->delete_temp("pending/xunshan");
		return do_xunshan(me);
	}

	return 0;
}

void ask_for_xunshan(CChar * me)
{
	if (! me->query_tempmap("xunshan"))
    {
		AddMenuItem(
	}

        if (! me->query_temp("xunshan/chaoyang"))
        {
              message_vision("$N����$n˵���㳯����ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/lianhua"))
               {
                      message_vision("$N����$n˵����������ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yuntai"))
               {
                      message_vision("$N����$n˵������̨��ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/sheshen"))
               {
                      message_vision("$N����$n˵������ôûȥ�����£�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/siguo"))
               {
                      message_vision("$N����$n˵���㵽��˼����ȥ�ˣ�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yunu"))
               {
                      message_vision("$N����$n˵���㵽��Ů����滪ɽС��ȥ�����ˣ�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               message_vision("$N����$n˵�����������ˡ������ȥ��Ϣȥ�ɡ�\n", this_object(), me);
               me->delete_temp("xunshan");                      
               me->add("combat_exp", random(100));
               return 1;
        }
        else
        {
               if ( query("xunshan") < 1)
               {
                      message_vision("$N����$n˵�������Ѿ�����Ѳɽȥ�ˡ������������ɡ�\n", this_object(), me);
                      return 1;
               }
               if( me->query("family/family_name") != "��ɽ��")
               {
                      message_vision("$N����$n���һ�������ɵ��Ӳ���Ѳɽ�����������ļ�ϸ���ݹ��ҽ��²����飡\n", this_object(), me);
                      this_object()->kill_ob(me);
                      return 1;
               }
               else
               {
                      add("xunshan", -1);
                      message_vision("$N����$n˵�����ɵ�������Ѳɽ���㣬�ܺã��ܺã����ȥ�ɡ�\n", this_object(), me);
                      me->set_temp("xunshan/start", 1);
                      me->set_temp("xunshan/time", time());
                      return 1;
               }
        }
}
*/
virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "��ɽȺ�ɹ�" ))
		return notify_fail("�����������");
	char msg[255];
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
	return 0;
}
ZUSHI_END;
