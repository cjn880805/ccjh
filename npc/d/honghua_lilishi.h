//lilishi.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_lilishi);

virtual void create()
{

	set_name("������","li li shi");

	set("title", "��ػ���ľ�û���");
	set("gender", "����");
	set("age", 45);
	set("str", 25);
	set("dex", 20);
	set("long", "����һ���ߴ����͵������ˣ����ϵ��·������廨������ȥ�е��̬��");
	set("combat_exp", 35000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 50);
	set_skill("force", 60);
	set_skill("blade", 90);
	set_skill("dodge", 70);
	set_skill("parry", 50);
	set_skill("wuhuduanmendao", 90);
	set_skill("yunlong_shenfa", 60);
	map_skill("blade", "wuhuduanmendao");
	map_skill("dodge", "yunlong_shenfa");
 	set("icon",young_man6);

	set("mp", 150); 
	set("max_mp", 150);
	set("mp_facotr", 10);
	set("chat_chance", 2);

    set_inquiry("�½���","����ܶ����ɲ����װ���");
	set_inquiry("��ػ�","ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��");
	set_inquiry("���","ֻҪ��������ػᣬ��������и�λ����ѧ���ա�");
    set_inquiry("���帴��","ȥ�ײĵ�ͻش�����ϸ���ưɣ�");
    set_inquiry("����","�����£�");
    set_inquiry("�п�","�����£�");
    set_inquiry("����",ask_zhu);
    set_inquiry("����ܽ����",ask_zhu);
    set_inquiry("�����˲���",ask_zhu);
    set_inquiry("����",ask_weiwang);

	carry_object("tudao")->wield();
	carry_object("cloth")->wear();
	add_money(20);
	set("no_huan",1);
}

virtual int accept_object(CChar * player ,  CContainer * ob)
{
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 10000) 
	{
		message_vision("��������$NһҾ����˵������λ�͹٣�Ҫʲô����˵",player);
		player->set_temp("money_paid",1);
		destruct(ob);
		return 1;
	}
	return 0;
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	char msg[255];

	npc->say(snprintf(msg,255,"%s�����ڵĽ���������%ld��",player->name(),player->query("����")),player);
//	npc->say(snprintf(msg,255,"%s�����ڵĽ���������%ld��",player->name(),player->query("weiwang")),player);
	npc->say("���������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦���������㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ",player);
	npc->say("ɱĳЩ���˻��ĳЩ���˿�����߽���������",player);
	npc->SendMenu(player);

	return "";

}


virtual char * chat_msg(CChar * player)
{
	switch(random(5))
	{
	case 0:
		return "������һ��ð����͵�����ȥ��";
	case 1:
		return "����ܽ������ֻ���ƽ�һ����˭��˭�򰡣�";
	case 2:
		return "�����˲�����ֻ���ƽ�һ����˭��˭�򰡣�";
	case 3:
		return "��ô�õ�������ôû��Ҫ����";
	case 4:
		return "�������Ž����֣��������ı����ġ�";
	}
	return "";
}

static char * ask_zhu(CNpc * npc , CChar * player)
{
	if (player->query_temp("money_paid"))
	{
		player->delete_temp("money_paid");
		player->set("huanggong/canenter",1);
		return "�������ڿ���������";
	}
	return "��ʲôҲ���Ƚ�Ǯ����";
} 



virtual int recognize_apprentice(CChar * player)
{
    if (player->query("weiwang")<50)
		return 0;

	return 1;
}


NPC_END;