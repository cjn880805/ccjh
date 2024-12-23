//liqingzhao.h
//code by zwb
//12-23
//inherit F_MASTER;

NPC_BEGIN(CNGuMu_liqingzhao);

virtual void create()
{
	set_name("������","li qing zhao");
	
	set("long", "�����ü�Ϊ��ò��������һ�ֺ�ʫ���������Ŀ�����˲���������");
	set("nickname", "��������");
	set("gender", "Ů��");
	set("rank_info/respect", "����");
	set("age", 27);
	set("attitude","heroism");
	set("str", 30);
set("foolid",58);
set("dex", 35);
	set("con", 17);
	set("int", 25);
	set("shen_type", -1);
	set("icon",taoistess);
	
	set("hp", 7500);
	set("max_hp", 10500);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 80);
	
	set("combat_exp", 1200000);
	
	
	set_skill("force", 200);
	set_skill("yunv_xinfa", 200);    //��Ů�ķ�
	set_skill("sword", 180);
	set_skill("yunv_jian", 180);     //��Ů��
	set_skill("dodge", 220);
	set_skill("yunv_shenfa", 220);   //��Ů��
	set_skill("parry", 200);
	set_skill("unarmed",200);
	set_skill("wudu_shenzhang", 220);    //�嶾����
	set_skill("wudu_xinfa", 220);
	set_skill("whip", 250);
	set_skill("swsb_whip", 250);//����������
	set_skill("literate", 180);
	set_skill("tianluo_diwang", 220);
	
	map_skill("force", "yunv_xinfa");
	map_skill("sword", "yunv_jian");
	map_skill("dodge", "yunv_shenfa");
	map_skill("parry", "wudu_shenzhang");
	map_skill("unarmed", "wudu_shenzhang");
	
	set_inquiry("����","վԶ�㣡");
	set_inquiry("����","�Ҳ��Ǳ����ˣ���֪����");
	set_inquiry("��","����������������˼֮�ࡢ���֮�⣿");
	set_inquiry("½��","�����Ǹ����������ʲô��");
	set_inquiry("ѩ","ѩ��һ���޵����µĵ���");
	set_inquiry("½����",ask_me );
	set_inquiry("����","�����ҵ�ʦ�á����������ʲô��");
	set_inquiry("������","�����ҵ�ʦ�棬�������ʵ�����ʣ�С���������㡣");
	set_inquiry("��������",ask_zhen );
	set_inquiry("���Ŀڷ�Һ","�����ұ�������Ķ��Ž�ҩ��ƽʱ���������յġ�" );
	
	create_family("��Ĺ��", 3, "����");
	set("chat_chance", 10);
	set_temp("have_zhen", 5);
	
	carry_object("greenrobe")->wear();
	carry_object("jingxin_san", 3);
	set("no_huan",1);
}

virtual char * chat_msg(CChar * player)
{
	switch(random(8))
	{
	case 0:
		return "�������������裬�������񣬸�����������䣬���Ǻ��ֱ������������";
	case 1:
		return "�����ϵر�˫�ɿͣ��ϳἸ�غ����";
	case 2:
		return "������Ȥ�����࣬���и��гն�Ů����";
	case 3:
		return "����Ӧ�����������ƣ�ǧɽĺѩ��ֻӰ��˭ȥ����";
	case 4:
		return "�����մ��Ɐ�У��������ǰ�Թ�������������·����į������ġ���������ƽ������";
	case 5:
		return "���л�Щ��ർ���ɽ��������ꡣ��";
	case 6:
		return "����Ҳ�ʣ�δ���ˣ�ݺ�����Ӿ��������";
	case 7:
		return "��ǧ����ţ�Ϊ����ɧ�ˣ����ʹ�����������𴦡���";
	}
	return "";
}

static char * ask_me(CNpc * npc , CChar * player)
{
	char msg[255];

	message_vision("��������Цһ���������������ȥ������", player);
	message_vision(snprintf(msg,255,"�����վ���ɱ��%s",player->name()),player);
    npc->kill_ob(player);
	return "";
}

static char * ask_zhen(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "��Ĺ��") && DIFFERSTR(player->querystr("class"), "taoist"))
		return "�㲻�������´��ˣ�����������";
	if(player->query_temp("mark/get_bt_zhen"))
		return "�㲻�Ǹ��ù��𣿲�Ҫ��ô̰�ĺò��ã�";
	if(npc->query("have_zhen") < 0)
		return "�������ˣ������Ѹ���������ͬ���ˡ�";

	load_item("bt_zhen")->move(player);

	player->set_temp("mark/get_bt_zhen",1);
	npc->add_temp("have_zhen", -1);

	message_vision("�����ո���$Nһ�ѱ������롣", player);
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "Snow blade") || DIFFERSTR(ob->querystr("name"), "��ѩ����ն") )
	{	
		message_vision("$N����ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "������", "mingyue pai");
	
	message_vision("$N���ͷ��͵͵��$nһ�鶫����", this, who);
	ob->move(who);

	return 1;
}

virtual void attempt_apprentice(CChar  * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "��Ĺ��"))
	{
		say(" �Ҳ��ձ��ɵ��ӡ�",player);
		SendMenu(player);
		return;
	}
	if(EQUALSTR(player->querystr("class"), "taoist"))
	{
		say(" �㲻ȥ��ص������������Ҹ�ʲô��",player);
		SendMenu(player);
		return;
	}
	if(player->query_dex() < 25)
	{
		say(" �����̫����ʺ�ѧ�ҹ�Ĺ�ɵ��书��",player);
		SendMenu(player);
		return;
	}
	if(player->query_int() < 35)
	{
		say(" �������̫����ʺ�ѧ�ҹ�Ĺ�ɵ��书��",player);
		SendMenu(player);
		return;
	}
	if(player->query("repute") > -50000)
	{
		say(" ���ǳ�����Ůħͷ���������л��뵱��ͽ�ܣ�",player);
		SendMenu(player);
		return;
	}
	if(player->query_skill("yunv_xinfa",1) < 90)
	{
		say(" ��ı����ķ����죬�������л��뵱��ͽ�ܣ�",player);
		SendMenu(player);
		return;
	}
	if(player->query_skill("tianluo_diwang",1) < 90)
	{
		say(" ������޵�����̫��������л��뵱��ͽ�ܣ�",player);
		SendMenu(player);
		return;
	}

	else
	{
	    say(" �ðɣ��Ҿ����������ͽ���ˡ�");
		recruit_apprentice(player);
	}
	return;
}

NPC_END;
