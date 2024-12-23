//tianjianshi.h
//code by zwb
//12-16

NPC_BEGIN(CNBingQi_ouyezi);

virtual void create()
{
		set_name("ŷұ��","ou ye zi");

        set("nickname", "���Ľ���");
		set("gender", "����" );
        set("age", 60);
        set("long", "��ͷ�ϰ���ͷ�����Ƴ���Ʈ����ǰ����Ŀ���ݵ������й⣬��Ŀ��������˸˸���ž��������ݵĽ��⣬�����ƺ�����Χ��һ�ɽ���֮�С�");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 30);
        set("shen_type", 0l);
		set("max_hp", 15000);
		set("mp_factor",50);
 	set("icon",old_man2);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("claw",200);
        set_skill("jiuyin_zhua",200);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("bibo_shengong",100);
        set_skill("luoying_shenjian",100);
        set_skill("parry",90);
        set_skill("anying_fuxiang",100);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",50);

		create_family("������",1,"����");

        set("combat_exp", 250000);
		set("score",0l);
	
        map_skill("force","bibo_shengong");
		map_skill("parry","luoying_shenjian");
		map_skill("sword","luoying_shenjian");
		map_skill("claw","jiuyin_zhua");
		map_skill("dodge","anying_fuxiang");

	
		set("attitude", "peaceful");
        
		set_inquiry("����" , "�������Ǽ�ʮ�ּ����£�Ҫ�����˵ľ��������������о��ĺ�������");
		set_inquiry("ԭ��" , "��������ǧ���������������ҵ����Ҳ��ܰ���������");
		set_inquiry("����" , do_weapon);
   
   
        set("chat_chance", 3);
        carry_object("cloth")->wear();
        carry_object("changjian")->wield();
		set("no_huan",1);
};

virtual char * chat_msg(CChar * me)
{
	switch(random(3))
	{
	case 0:
		return "ŷұ�Ӹ������裺��������⣬�����͡����������⣬��Ӣ�ۣ�";
	case 1:
		return "ŷұ�ӵ�ͷ�������ƺ���˼��ʲô��";
	case 2:
		return "ŷұ��̾��һ�����������Ӣ�ۣ���Ӣ�ۡ�����������";
	}
	return "";
}

virtual int accept_object(CChar * player,CContainer * ob)
{
	char msg[255];

	string name = ob->querystr("name");

	if( name ==	"������"
		|| name == "�л���"
		|| name == "����"
		|| name == "��а����"
		|| name == "�׻�������"
		)
	{
		if(DIFFERSTR(player->querystr_temp("condition"), ob->querystr("name")) )
		{
			say("�Ҷ���˵����Ҫ��������ô��", player);
			SendMenu(player);
			return 2;
		}
		else 
		{
			player->delete_temp("condition");
			say("�ܺúܺã����ҾͰ�����һ�ΰɣ�", player);
			player->set_temp("condition_ok",1);
			do_weapon(this,player);
			SendMenu(player);
			return 2;
		}
	}

	if(player->query("weapon/make"))
	{
		say("���Ѿ���һ������������ˣ�������ʲô���ѵ�������ô��", player);
		SendMenu(player);
		return 2;
	}

	name = ob->querystr("id");

	if(name=="shen mu")
	{
		player->set_temp("or",1);
		player->set_temp("get_orc",1);
	}
	else if(name=="jin mu")
	{
		player->set_temp("or",2);
		player->set_temp("get_orc",1);
	}
	else if(name=="han zhu")
	{
		player->set_temp("or",3);
		player->set_temp("get_orc",1);
	}
	else 
	{
		say("����ʲô���ⲻ���������������", player);
		SendMenu(player);
		return 2;
	}

	say(snprintf(msg, 255, "��λ%sҪ��ʲô�����������˸����ҡ�", query_respect(player)));
	AddMenuItem("��", "sword", player);
	AddMenuItem("��", "blade", player);
	AddMenuItem("��", "club", player);
	AddMenuItem("��", "staff", player);
	AddMenuItem("��", "hammer", player);
	AddMenuItem("��", "whip", player);
	SendMenu(player);
	player->set_temp("mark/ŷұ��", 1);
	return 2;
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	CChar * player;
	player=me;

	if(player->query_temp("mark/ŷұ��"))
	{
		player->delete_temp("mark/ŷұ��");
		if(! ask || ! strlen(ask)) return 0;
		return do_answer(player, ask);
	}

	return CNpc::do_talk(player, ask);
}

int do_answer(CChar * player, string arg)
{
	//CChar * player;
	//player=me;

	if(! player->query_temp("get_orc") )
	{
		say("���ҵ�ԭ������", player);
		SendMenu(player);
		return 0;
	}
	
	if(arg == "sword" )
	{
		player->add_temp("sword", 1);
		say("����ԭ��ȥ���̽��ɣ�", player);
	}
	else if(arg == "blade")
	{
		player->add_temp("blade",1);
		say("����ԭ��ȥ���̵��ɣ�", player);
	}
	else if(arg == "club")
	{
		player->add_temp("club",1);
		say("����ԭ��ȥ���̹��ɣ�", player);
	}
	else if(arg == "staff" )
	{
		player->add_temp("staff",1);
		say("����ԭ��ȥ�����Ȱɣ�", player);
	}
	else if(arg == "hammer")
	{
		player->add_temp("hammer",1);
		say("����ԭ��ȥ���̴��ɣ�", player);
	}
	else if(arg == "whip")
	{
		player->add_temp("whip",1);
		say("����ԭ��ȥ���̱ްɣ�", player);
	}
	else
	{
		return notify_fail("ŷұ����ϸ��˵�����²��ɶ�Ϸ��������!!");
	}

	SendMenu(player);

	CContainer * w_or;
	switch ( player->query_temp("or") ) 
	{
	  case 1:
		w_or = load_item("/d/npc/m_weapon/tan/item/shenmu");
		w_or->move(player);
		message_vision("ŷұ�Ӹ���$Nһ��ǧ����ľ��", player);
		break;
	  case 2:
		w_or = load_item("/d/npc/m_weapon/tan/item/jinmu");
		w_or->move(player);
		message_vision("ŷұ�Ӹ���$Nһ�麣�׽�ĸ��", player);
		break;
	  case 3:
		w_or = load_item("/d/npc/m_weapon/tan/item/hanzhu");
		w_or->move(player);
		message_vision("ŷұ�Ӹ���$Nһ�麮˿����", player);
		break;
	}

	return 1;
}

static char * do_weapon(CNpc * npc , CChar * this_player)
{
	char w_id;
	CContainer * weapon;
	char msg[255];

	w_id=this_player->query("weapon/id");

	if(!this_player->query("weapon/make"))
	{
		npc->say("�����������",this_player);
		return "";
	}

	if(this_player->Present(w_id))
	{
		npc->say("ŷұ����ɫһ���������������������ֱ�ô��������ʲô��",this_player);
		npc->SendMenu(this_player);
		return "";
	}

	if(this_player->query_temp("condition"))
	{
		npc->say(snprintf(msg,255,"ŷұ����ɫһ������������ȥ��%s��ô����û�õ��ͻ������",this_player->query_temp("condition")),this_player);
		npc->SendMenu(this_player);
		return "";
	}

	if(!this_player->query_temp("condition_ok"))
	{
		npc->say(snprintf(msg,255,"��λ%s��Ҫ���µõ��������ⲻ�ѡ���������ҵ���Ҫ�Ķ�����",query_respect(this_player)),this_player);

		switch(random(5))
		{
		case 0:
			npc->say("���õ������ӣ������ɣ�",this_player);
			this_player->set_temp("condition","������");
			break;
		case 1:
			npc->say("���ҽл������ҾͰ��㣡��",this_player);
			this_player->set_temp("condition","�л���");
			break;
		case 2:
			npc->say("��...����ú�ľ�°׻������������ɣ���",this_player);
			this_player->set_temp("condition","�׻�������");
			break;
		case 3:
			npc->say("....���뿴������������",this_player);
			this_player->set_temp("condition","����");
			break;
		case 4:
			npc->say("������������ҵ���а���׵Ļ�......",this_player);
			this_player->set_temp("condition","��а����");
			break;
		}
		npc->SendMenu(this_player);
	}
	else
	{
		this_player->delete_temp("condition_ok");
		weapon=create_weapon(this_player);
		weapon->move(this_player);
	}

	return "";
}

static CContainer * create_weapon(CChar * this_player)
{
	CContainer * weapon;
	string mask;	//the varible that record the type of weapon
	mask = this_player->query("weapon/type");

	if(mask=="��")
	{
		weapon = load_item("m_sword");
		return weapon;
	}
	else if(mask=="��")
	{
		weapon = load_item("m_blade");
		return weapon;
	}
	else if(mask=="��")
	{
		weapon =load_item("m_club");
		return weapon;
	}
	else if(mask=="��")
	{
		weapon =load_item("m_staff");
		return weapon;
	}
	else if(mask=="��")
	{
		weapon =load_item("m_hammer");
		return weapon;
	}
	else if(mask=="��")
	{
		weapon =load_item("m_whip");
		return weapon;
	}
	
	return NULL;
}

NPC_END;
