//tonglao.h
//Lanwood 2000-01-08

ZUSHI_BEGIN(CNlingjiu_tonglao);

virtual void create()
{
	set_name("��ɽ����",  "tie lao");
	set("long", "�����ǡ����չ����Ŀ�ɽ��ʦ.էһ���ƺ��Ǹ�ʮ�߰����Ů��,������ȴ����������.");
	set("title", "���չ�����");
	set("gender", "Ů��");
	set("per", 20);
	set("age", 96);
	set("nickname",  "Ψ�Ҷ���");
	
	set("attitude", "peaceful");
	set("icon",young_woman1);

	set("str", 25);
	set("int", 35);
	set("con", 40);
	set("dex", 40);

	set("hp", 20000);
	set("max_hp", 20000);
	
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 200);

	set("combat_exp", 55000000);
	set("score", 200000);
	set_skill("force", 280);
	set_skill("unarmed", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
//	set_skill("finger",280);
	set_skill("hand",400);
	set_skill("strike", 280);
    set_skill("sword",280);

	set_skill("zhemei_shou",280);
	set_skill("liuyang_zhang",280);
    set_skill("tianyu_qijian",300);
	set_skill("yueying_wubu",280);
	set_skill("bahuang_gong", 300);
	set_skill("rouqing_zhi",200);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
    map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
    map_skill("sword","tianyu_qijian");
//	map_skill("finger","rouqing_zhi");

	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand","zhemei_shou");
	create_family("���չ�",1,"����");
	set("chat_chance_combat", 50);
	
 	carry_object("changjian")->wield();
 	carry_object("qingyi")->wear();
    carry_object("doupeng")->wear();
    carry_object("jiudai");

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("no_huan",1);

	set_inquiry("��������ʧ��",ask_lost);
};

static char * ask_lost(CNpc * npc , CChar * player)
{
	char msg[255];
	if(player->querymap("lj") && !player->query("lj/renwu_lost"))
	{
		if(player->query("lj/renwu7"))
		{
			player->del("lj");
			player->delete_temp("lj");
			player->set("hp",100);
			player->set("eff_hp",100);
			player->set("mp",0l);
			player->add("combat_exp",-12000);
			player->UpdateMe();
			return snprintf(msg,255,"%sҲ�Ƚ������ˣ�������Ҳ�Ͳ�ָ�����˰ɣ�",player->name());
		}
		else if(player->query("lj/renwu6")||player->query("lj/renwu5"))
		{
			player->del("lj");
			player->delete_temp("lj");
			player->set("hp",100);
			player->set("eff_hp",100);
			player->set("mp",0l);
			player->add("combat_exp",-7000);
			player->UpdateMe();
			return snprintf(msg,255,"%sҲ�����ˣ�������Ҳ�Ͳ�ָ�����˰ɣ�",player->name());
		}
		else
			return snprintf(msg,255,"%s���ܰ�;�����أ��ҿ���ȫ�����������ˡ�",player->name());
	}
	else
		return "�����Һ���û��ʲô��ϵ��������ʲô����ʧ���أ�";
}

virtual char * chat_msg_combat()
{
	char msg[40];
	CContainer * jian = PresentName("changjian", IS_ITEM);

	switch(random(8))
	{
	case 0:
			perform_action("strike zhong", 1);
			break;
	case 1:
			perform_action("hand duo", 1);
			break;
	case 2:
			perform_action("sword san", 1);
			break;
	case 3:
	case 4:
			if(query_weapon() == jian && jian)
				command(snprintf(msg, 40, "unwield %ld", jian->object_id()));
			break;
	case 5:
	case 6:
			if(jian && ! query_weapon())
				command(snprintf(msg, 40, "wield %ld", jian->object_id()));
			break;
	case 7:
	case 8:
			perform_action("force recover", 0);
			break;
	}
	
	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];
	if (DIFFERSTR(me->querystr("gender"), "Ů��"))
    {
 		say("��������!", me);
		SendMenu(me);
		return;
	}

	if ( me->query_skill("bahuang_gong", 1) < 230) 
    {
		say(snprintf(msg, 255, "%s�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�", query_respect(me)), me);
		SendMenu(me);
		return;
	}  

	if (me->query_con() < 30) 
    {
		say("���Ź�����Ϊ����,��ĸ����ƺ�����.", me);
		SendMenu(me);
		return;
	}

    command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "officer");
	me->UpdateMe();
    
}
/*
virtual int accept_object(CChar * who, CContainer * ob)
{
	if (  DIFFERSTR(ob->querystr("name"), "ʮ����ż"))
		return 0;

	destruct(ob);
	say("����������������ʱ������ӡ����������Ⱦ�һ�£���Ȼ�������", who);
	SendMenu(who);
	who->add_temp("tmark/rouqing", 8);
	return 1;
	
}
*/

virtual void init(CChar * me)
{
	CNpc::init(me);

	char msg[255];
	if(userp(me) && !is_fighting() && me->query("lj/renwu_ok"))
	{
		int time=int(me->query("lj/renwu_ok")*me->query("lj/renwu_level")*me->query("int")/10);
		tell_object(me, "\n$HIR��ɽ���ѣ�Ц�����Ǻǣ����ѵ���˵����ɽ������ƽ�����˵�л����������������������պ���в�����");
		if(EQUALSTR(me->querystr("family/family_name"), "���չ�") )
		{
			tell_object(me, "$HIR�����Ҿ�׼����������չ�����֮�������书��");
			me->set("lj/jiangli_time",time);
		}
		else
			tell_object(me, "$HIR�����Ҿͳ���գ��ú�ָ��ָ������书��");
		int exp=me->query("lj/renwu_ok")*(48000+me->query("level")*50);
		int repute=random(100000)+100000;
		if(me->query("repute")<0)
			repute=-repute;
		me->add("combat_exp",exp);
		me->add("repute",repute);
		me->set("xkd/lingjiu",1);
		me->UpdateMe();
		if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") )
		{
			message_vision(snprintf(msg, 255, "\n$HIR$N�����������������������õ���ɽ������ʶ����þ���%d�㽱������������������%d�㡣",exp,repute),me);
			me->del("lj");
			me->delete_temp("lj");
		}
		else if(EQUALSTR(me->querystr("family/family_name"), "���չ�") )
		{
			message_vision(snprintf(msg, 255, "\n$HIR$N�����������������������õ���ɽ������ʶ����þ���%d�㽱������������������%d�㡣",exp,repute),me);
			message_vision(snprintf(msg, 255, "$HIR����������չ���԰��ɽ���ʯ���в����书$YEL%d��$HIR�Ľ�����\n",time),me);
			if(!me->query("lj/renwu10"))
			{
				me->del("lj/����");	
			}
			me->del("lj/renwu_ok");
			me->del("lj/renwu_level");
		}
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "���ձչ���" ))
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



