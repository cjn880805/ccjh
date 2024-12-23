// pub_susu.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_susu);

virtual void create()
{
	set_name("素素", "susu" );

	set("icon", young_woman2);
	set("nickname", "伺茶丫鬟");
	set("gender", "女性" );
	set("age", 14+random(3));
	set("long","这是个年年龄不大的小丫鬟，但宽松的衣服也遮不住她过早发育的身体。一脸聪明乖巧，满口伶牙俐齿。见有人稍微示意，便过去加茶倒水。");
	set("attitude", "friendly");
	set("shen_type", 1);
	
	set("str", 20);
	set("int", 28);
	set("con", 24);
	set("dex", 20);
	
	set("max_hp", 450);
	set("mp", 150);
	set("max_mp", 150);
	set("combat_exp", 1000+random(800));
	set("score", 1000);
	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 15+random(10));
	set_skill("parry", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/cdamage", 3);
	
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"素素笑吟吟地说道：这位%s请先入座，我这就给您上茶。",query_respect(ob) );
}

/*
void serve_tea(CChar * who)
{
	CContainer * obn;
//	CRoom * room;
	
	if( !who->query_temp("marks/sit") ) return;
	
//	if( !(room = environment()) ) return;
	
	obn = load_item("cha");//醉仙茶
//	obn->move(load_room(room));
	message_vision("素素拿出一个小茶壶，沏上一杯香浓的碧螺春．",who);
	
	obn = load_item("gao");//冰雪翡翠糕
//	obn->move(load_room(room));
	message_vision("素素拿出一碟精致的四色点心，放在桌上．", who);
	
	return;
}
*/

NPC_END;