//fawang.h
//code by zwb
//1-15
//inherit F_MASTER;

ZUSHI_BEGIN(CNxueshan_fawang);

virtual void create()
{
	   set_name("��������", "inlun fawang");
	   set("long","����ѩɽ�µĻ��̷�������ѩɽ�µĵ�λ�������������Ħ�㡣��һ���Ϻ����ģ�ͷ��ɮñ��");
	   set("title", "����" );
	   set("gender", "����");
	   set("age", 50);
	   set("icon",old_man1);
	   set("foolid",156);        
	   set("attitude", "peaceful");
	   set("shen_type", -1);
	   set("str", 30);
	   set("int", 30);
	   set("con", 30);
	   set("dex", 30);
	   set("max_hp", 15000);
	   set("mp", 4500);
	   set("max_mp", 4500);
	   set("mp_force", 100);
	   set("combat_exp", 1500000);
	   set("score", 200000);
	   
	   set_skill("force", 280);
	   set_skill("xiaowuxiang", 280);
	   set_skill("dodge", 280);
	   set_skill("shenkong_xing", 280);
	   set_skill("unarmed", 280);
	   set_skill("yujiamu_quan", 250);
	   set_skill("parry", 250);
	   set_skill("sword", 250);
	   set_skill("mingwang_jian", 250);
	   set_skill("mizong_xinfa", 300);
	   set_skill("literate", 280);
	   set_skill("hammer", 320);
	   set_skill("riyue_lun", 320 );
	   
	   
	   map_skill("force", "xiaowuxiang");
	   map_skill("dodge", "shenkong_xing");
	   map_skill("unarmed", "yujiamu_quan");
	   map_skill("parry", "riyue_lun");
	   map_skill("sword", "mingwang_jian");
	   map_skill("hammer", "riyue_lun");
	   
	   create_family("ѩɽ��", 2, "���̷���");
	   set("class", "bonze");
	   
	   carry_object("jinlun")->wield();
	   carry_object("p_jiasha")->wear();
	   carry_object("sengmao")->wear();
	   add_money(5000);
	   set("no_huan",1);
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[40];
	
	if (DIFFERSTR(player->querystr("gender"), "����"))
		  {
		say(" ��ϰ�����ڹ���Ҫ����֮�塣",player);
		say(" ��λʩ��������ذɣ�",player);
		SendMenu(player);
		return;
		  }
	
		  if (DIFFERSTR(player->querystr("class"), "bonze"))
		  {
			  say(" �ҷ��ŵ����������ࡣ",player);
			  say(" ��λʩ��������ذɣ�",player);
			  SendMenu(player);
			  return;
		  }
		  
		  if (DIFFERSTR(player->querystr("family/family_name"), "ѩɽ��"))
		  {
			  say(" ��λʩ���ȷǱ��µ��ӣ�������ذɣ�",player);
			  SendMenu(player);
			  return;
		  }
		  
		  if (player->query_skill("mizong_xinfa", 1) < 100) 
		  {
			  say(" ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�",player);
			  say(" ��λʩ���Ƿ�Ӧ�ö�����б��ŵ��ķ���",player);
			  SendMenu(player);
			  return;
		  }
		  g_Channel.do_emote(this, player, "smile", 0);
		  g_Channel.do_emote(this, player, "nod", 0);
		  
		  say("�������ѧϰ�𷨰ɣ�");		
		  command(snprintf(msg,40,"recruit %ld",player->object_id()) );
		  
		  player->set("title","���");
		  player->UpdateMe();
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "ѩɽ�´��" ))
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