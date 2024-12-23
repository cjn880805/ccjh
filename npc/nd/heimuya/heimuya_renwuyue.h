//renwuyue.h	������
//code by zwb
//12-16
//inherit F_MASTER;


NPC_BEGIN(CNHeiMUYa_renwuyue);

virtual void create()
{
	set_name("������","ren wuyue");

	set("title",  "�������ԭ����" );
	set("long", "ֻ����һ�ų��������ף���ɫѩ�ף����ް��Ѫɫ��üĿ����,������ߣ�һͷ�ڷ���������һϮ������");
	set("gender", "����");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",old_man2);
	
	set("hp", 9000);
	set("max_hp", 9000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 400);
	set("combat_exp", 6000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("changquan", 200);
	set_skill("xingxiu_duzhang", 200);
	set_skill("lingxu_bu", 200);
	set_skill("damo_jian", 200);
	set_skill("taiji_jian", 200);
	set_skill("huifeng_jian", 200);
	set_skill("taishan_sword", 200);
	set_skill("hengshan_jian", 200);
	set_skill("hengshan_sword", 200);
	set_skill("huashan_sword", 200);
	set_skill("songshan_sword", 200);

	map_skill("dodge", "lingxu_bu");
	map_skill("force", "kuihua_xinfa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");

	set_inquiry("�Ƚ�",ask_bijian);
	set_inquiry("����",ask_jiaozhu);
	set_inquiry("��ľ��","Ҫ�ú�ľ��Ϸ����ȿ�����Ľ�����");

	carry_object("bluecloth")->wear();
	carry_object("changjian")->wield();
}

static char * ask_bijian(CNpc * npc , CChar * player)
{
	CContainer * obj;
	char msg[255];
	LONG ID=player->object_id();

	message_vision("$N����˵�������������Ұݼ�����ǰ�����������ָ�̡���\n$nЦ���������ÿ������������Ҽ�į���ɶ�л��������\n$N���������ҡ���\n$n���˵�ͷ��˵��������ֻ��������Ľ�����������Ĺ��У���˵����Ҳδ����ʤ�����㡣��\n$n�´��һ���������ֽ�������", 
		player, npc);

	g_Combatd.Do_Attack(npc,player, CCombatd::TYPE_QUICK);

	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("������̾�˿�����˵��������һ�С���", player);
		return "";
	}

	npc->command("enable 0 sword taiji_jian");
	message_vision("�����´��һ�������䵱��������", player);
	g_Combatd.Do_Attack(npc, player, CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("������̾�˿�����˵�����������С���",player);
		return "";
	}

	npc->command("enable 0 sword huifeng_jian");
	message_vision("�����´��һ���������ҽ�������",player);
	g_Combatd.Do_Attack(npc,player, CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("������̾�˿�����˵�����������С���",player);
		return "";
	}

	npc->command("enable 0 sword songshan_sword");
	message_vision("�����´��һ��������ɽ��������",player);
	g_Combatd.Do_Attack(npc,player,CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("������̾�˿�����˵�����������С���",player);
		return "";
	}
	
	npc->command("enable 0 sword taishan_sword");
	message_vision("�����´��һ������̩ɽ��������", player);
	g_Combatd.Do_Attack(npc,player,CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0|| !(npc->environment())->Present(ID))
	{
		message_vision("������̾�˿�����˵�����������С���",player);
		return "";
	}
	
	npc->command("enable 0 sword huashan_sword");
	message_vision("�����´��һ��������ɽ��������",player);
	g_Combatd.Do_Attack(npc,player,CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0  || !(npc->environment())->Present(ID))
	{
		message_vision("������̾�˿�����˵�����������С���",player);
		return "";
	}
	
	npc->command("enable 0 sword hengshan_sword");
	message_vision("�����´��һ��������ɽ��������",player);
	g_Combatd.Do_Attack(npc,player,CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("������̾�˿�����˵�����������С���",player);
		return "";
	}
	
	npc->command("enable 0 sword hengshan_jian");
	message_vision("�����´��һ��������ɽ��������",player);
	g_Combatd.Do_Attack(npc,player,CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("������̾�˿�����˵����������û�����С���",player);
		return "";
	}

	obj = load_item("kuihua");
	obj -> move(player);
	npc->say(snprintf(msg,255,"����λ%s������ľ������ûʲô���ˣ�����һ����ɣ��������������Լ������ˡ���",query_respect(player)), player);
	npc->SendMenu(player);
	return "";
}


static char * ask_jiaozhu(CNpc * npc , CChar * me)
{
	CContainer * obj;
	char msg[255];
	if(me->query("level") < 45 ||me->query_temp("ry/renwu1_1"))
	{
		npc->say(snprintf(msg,255,"����λ%s������û������Щ��ʲô����",query_respect(me)), me);
		npc->SendMenu(me);
		return "";
	}
	if ( me->query("ry/jq")==me->query("age") )
	{
		npc->say(snprintf(msg,255,"����λ%s��������Щʲô�أ���",query_respect(me)), me);
		npc->SendMenu(me);
		return "";
	}

	obj = load_item("baozi");
	obj->set_name("22���Ͷ�������չ��Ʊ","men piao");
	obj->set("long","����һ�ű�����ֽƬ������д�š�22���Ͷ�������չ�볡����������");
	obj->set("owner1",me->id(1));
	obj->set("ry/menpiao",1);
	obj -> move(me);
	npc->say(snprintf(msg,255,"����λ%s����������Ī��Ҳ�������ţ�����ǰ�ν����������ƺ���û������������������һ�������ıܵ����ڣ����ĸ��ֱ��ݺ��١��塢�顢�������ָ��ֿ��ܡ���",query_respect(me)), me);
	npc->say(snprintf(msg,255,"��������һ������չ��Ʊ���������ǻ�ϲ������������ɣ�ϣ�������ҵ������ȳ������˼ҡ���", me);
	npc->say(snprintf(msg,255,"��������ʵ��Ҳ��������˵�ģ�˭֪�������Ǽ��ء���ɱ���߱��ˣ��͵���û˵�����ˡ���", me);
	npc->SendMenu(me);
	me->set_temp("ry/renwu1_1",1);//�������������õ���Ʊ
	me->set_temp("no_fei",1);
	tell_object(me,"\n$HIC��õ�����1��22���Ͷ�������չ��Ʊ��\n");
	return "";
}

NPC_END;
