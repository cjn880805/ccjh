//xu.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

SHENLONG_BEGIN(CNshenlong_xu);

virtual void create()
{
	set_name("��ѩ��","xu xuege");
	set("title", "����������ʹ");
	set("nickname",  "��Ѫ����" );
	set("long", "���Ǹ���ʮ����ĸ��ݺ��ӣ���һϮ���£���Ȼͦ����" );
	set("icon",young_man5);	
	
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("con", 30);
	set("max_hp", 9000);
    set("hp",3000);
	set("max_mp",1000);
    set("mp",1000);
	set("mp_factor", 50);
	set("combat_exp", 500000);
	set("score", 40000);
	set("shen_type", -1);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);

    set_skill("force", 100);
    set_skill("dodge", 100);
    set_skill("unarmed", 100);
    set_skill("strike", 90);
    set_skill("parry", 100);
    set_skill("staff", 90);
    set_skill("sword", 90);
	set_skill("literate", 90);
	
	set_skill("shenlong_xinfa", 90);
	set_skill("yixingbu", 90);
	set_skill("shenlong_bashi", 90);
	set_skill("huagu_mianzhang", 90);
	set_skill("shedao_qigong", 90);
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");

	prepare_skill("unarmed", "shenlong_bashi");
	prepare_skill("strike", "huagu_mianzhang");

	create_family("������",2,"����");

	set_inquiry("�ٻ����߸�",ask_gao);
    set_inquiry("���",do_join);
	set_inquiry("�鰲˳","����Ƣ������,Ҫ�������Ĳź�");
	set_inquiry("����","����Ƣ������,Ҫ�������Ĳźá�");
	set_inquiry("�ں�","���겻��!�����ɸ�!��������!������ʥ!");

	set("chat_chance", 3);
	set("chat_chance_combat", 30);

    carry_object("duanjian")->wield();
	set("no_huan",1);
}

static char * ask_gao(CNpc * npc , CChar * player)
{
	return "��ѩͤ��������˵������Ǳ��̽��ﰡ����һ����Ѫ������Ũ�㣬����ס�������ߵ��ϣ����˶��������ۻƾƣ��Աܶ��ߣ��������һ�����ۻƾƣ���ʹ�˽���������ܶ��������ˣ�����ôҲ֪����";
}

static char * do_join(CNpc * npc , CChar * player)
{
	if (player->query("repute") > 0)
	{
		message_vision("$N��$n��ŭ����������̣�һ����Ͳ��Ǻ���! ", npc, player);
		npc->kill_ob(player);
		return 0;
	}

	if(player->querymap("party") && DIFFERSTR(player->querystr("party/party_name"), "������"))
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ�������������ˣ����������������̡�", npc, player);
		return 0;
	}

	if(player->query("age") > 24)
	{
		message_vision("$N���ε�ҡҡͷ��$n˵����������ֻϲ������������Ů�����ޱ�����Ե����", npc, player);
		return 0;
	}

	if( EQUALSTR(player->querystr("party/party_name"), "������") )
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ����������̵����ˡ�",npc, player);
		return 0;
	}

	char new_rank[40];
	snprintf(new_rank, 40, "����ʹ����");
	player->set("party/party_name","������");
	player->set("party/rank", new_rank);
	player->set("party/level", 1);
	
	g_Channel.do_emote(npc,player, "smile", 0);
	message_vision("$N��$n˵���������ʱ�ڱ�ʹ����Ч���ɣ�",npc,player);
	return 0;
}

virtual  char  * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "��ѩ���Ȼһ���Դ���˵�����ˣ������ðٻ����߸࣡";
	case 1:
		return "��ѩ��ŭ��������ټ��һ�������̣�������һ�����������ˣ�";
	case 2:
		return "��ѩ��̾������˵����������ɱ�˺鰲˳��˭Ҳ��ˡ�";
	}
	return "";
}

virtual int  accept_object(CChar * player , CContainer * obj)
{
	CContainer * obn;
	if (!obj)
	{	
		say("��û�����������",player);
		SendMenu(player);
		return 0;
	}

	if ( DIFFERSTR(obj->querystr("base_name"), "���ߵ�") && DIFFERSTR(obj->querystr("base_name"), "���㻨" ))
	{
		say("��ѩ��ҡͷ�������ɱ���˺鰲˳������ʲôҲû�ð�������",player);
		SendMenu(player);
		    return 0;
	}

	if(EQUALSTR(obj->querystr("base_name"), "���ߵ�"))
	{
		  if(query_temp("baixianghua"))
		  {
			  message_vision("��ѩ����Ǹ��ߵ�����ϲ�������ߵ����㻨������,�ٻ����߸�������!",player);
			  obn=load_item("baihua");
              obn->move(player);
		      delete_temp("fushedan");
		      delete_temp("baixianghua");
 	          return 1;		 
		  } 		
		  else	
		  {	
			if(query_temp("fushedan"))
			{
			  message_vision("��ѩ����Ǹ��ߵ�����$Nҡͷ�������ߵ������ˣ��Ͳ���㻨�ˡ�",player);
			  return 0;
			}
			else	  
			{
			  message_vision("��ѩ�󿴼����ߵ�����ϲ�������˸��ߵ���ֻ����㻨�ˡ�",player);
			  set_temp("fushedan",1);	
	          return 1;
			}
		  }
	}
	if (EQUALSTR(obj->querystr("base_name"), "���㻨" ))
	{
		  if(query_temp("fushedan"))
		  {
		  message_vision("��ѩ����ǰ��㻨����ϲ�������ߵ����㻨������,�ٻ����߸�������!",player);
		  obn=load_item("baihua");
          	  obn->move(player);
		  delete_temp("fushedan");
		  delete_temp("baixianghua");
 	          return 1;		 
		  } 		
		  else	
		  {	
			if(query_temp("baixianghua"))
            {
				message_vision("��ѩ����ǰ��㻨����$Nҡͷ�������㻨�����ˣ��Ͳ�ߵ��ˡ�",player);
			   return 0;
			}
			else	  
            {
				message_vision("��ѩ�󿴼����㻨����ϲ�������˰��㻨��ֻ��ߵ��ˡ�",player);
				set_temp("baixianghua",1);	
				return 1;
			}
		 }	
	}
	return 0;
}

NPC_END;