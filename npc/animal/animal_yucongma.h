//yucongma.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_yucongma);

virtual void create()
{
	set_name("������","yu cong ma");

	set("icon", tiger);

	set("race", "Ұ��");
	set("gender", "����");
	set("age", 2+random(3));
	set("long", "����һƥ������������ǧ�ҹ�а˰١���ҿ���������ȥ�κεط�");
	set("int", 30);
	set("hp", 300);
	set("max_hp", 900);
	
	set("combat_exp",50000);
	set("attitude", "peaceful");

	CVector v;

	v.append("bite");
	v.append("hoof");
	set("verbs", v);

	set_inquiry("����",do_ride);

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);
};

virtual void init(CChar * player)
{
	player->set_temp("pending/go_where",0l);
}

static  char * do_ride (CNpc * npc, CChar * player )
{
    char msg[255];

    if(player->query("mp")<0)
    {
          message_vision("$NһԾ�������������ֻ�����������쳤Х��ͻȻ��Ȼһ��......��$N�ݺ�ˤ���˵��ϣ����$N���˵����ˡ�" ,player);
          player -> receive_damage ("hp",50) ;
          player -> receive_wound  ("hp",50) ;
          return "";
    }

	player->set_temp("onhorse",1);
//	npc->set("rider",player->object_id());
	message_vision("$NһԾ�������������" , player );

	npc->command(snprintf(msg,255,"follow %ld",player->object_id()));

	player->set_temp("pending/go_where", 1);

	npc->AddMenuItem("������", "����", player); 
	npc->AddMenuItem("���ݳ�", "���ݳ�", player); 
	npc->AddMenuItem("������", "������ʯ��", player); 
	npc->AddMenuItem("����ɽ", "����ɽ����", player); 
	npc->AddMenuItem("���޺�", "���޺���ɽɽ·1", player); 
	npc->AddMenuItem("�����", "�����", player); 
	npc->AddMenuItem("Ȫ  ��", "Ȫ��", player); 
	npc->SendMenu(player);

    return ""; 
}


virtual int do_talk(CChar * player, char * ask = NULL)
{
	if(! ask) return 0;

	if(player->query_temp("pending/go_where"))
	{
		return do_go(player,ask);
	}

	return CNpc::do_talk(player, ask);
}

int do_go(CChar * player , char  * dest)
{
	CRoom * r = load_room(dest);
    player->move(r);
    this->move(r);
    message_vision("ֻ��$N������������������\n������ǰ��$N����һת��Ծ����������̬ʮ��������" , player );
	player->delete_temp("pending/go_where");
 //   delete("rider");
    player->delete_temp("onhorse");
    command("follow none");
	return 1;
}

NPC_END;
