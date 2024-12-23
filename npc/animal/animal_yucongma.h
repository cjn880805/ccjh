//yucongma.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_yucongma);

virtual void create()
{
	set_name("玉骢马","yu cong ma");

	set("icon", tiger);

	set("race", "野兽");
	set("gender", "雄性");
	set("age", 2+random(3));
	set("long", "这是一匹玉骢宝马，日行千里，夜行八百。玩家可以骑上它去任何地方");
	set("int", 30);
	set("hp", 300);
	set("max_hp", 900);
	
	set("combat_exp",50000);
	set("attitude", "peaceful");

	CVector v;

	v.append("bite");
	v.append("hoof");
	set("verbs", v);

	set_inquiry("骑马",do_ride);

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
          message_vision("$N一跃身跨上了玉骢马。只见玉骢马仰天长啸，突然猛然一颠......把$N狠狠摔在了地上，结果$N受了点轻伤。" ,player);
          player -> receive_damage ("hp",50) ;
          player -> receive_wound  ("hp",50) ;
          return "";
    }

	player->set_temp("onhorse",1);
//	npc->set("rider",player->object_id());
	message_vision("$N一跃身跨上了玉骢马。" , player );

	npc->command(snprintf(msg,255,"follow %ld",player->object_id()));

	player->set_temp("pending/go_where", 1);

	npc->AddMenuItem("北京城", "北京", player); 
	npc->AddMenuItem("扬州城", "扬州城", player); 
	npc->AddMenuItem("少林寺", "少林寺石阶", player); 
	npc->AddMenuItem("白陀山", "白驼山东街", player); 
	npc->AddMenuItem("星宿海", "星宿海天山山路1", player); 
	npc->AddMenuItem("大理城", "大理城", player); 
	npc->AddMenuItem("泉  州", "泉州", player); 
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
    message_vision("只见$N骑着玉骢马急奔而来。\n奔到近前，$N身行一转，跃下马来，姿态十分优美。" , player );
	player->delete_temp("pending/go_where");
 //   delete("rider");
    player->delete_temp("onhorse");
    command("follow none");
	return 1;
}

NPC_END;
