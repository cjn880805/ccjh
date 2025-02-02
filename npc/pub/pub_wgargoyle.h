// pub_wgargoyle.c


NPC_BEGIN(CNpub_wgargoyle);
/*
string *death_msg = ({
	"白无常说道：喂！新来的，你叫什么名字？"  ,
		"白无常用奇异的眼光盯著你，好像要看穿你的一切似的。"  ,
		"白无常「哼」的一声，从袖中掏出一本像帐册的东西翻看著。"  ,
		"白无常合上册子，说道：咦？阳寿未尽？怎么可能？"  ,
		"白无常搔了搔头，叹道：罢了罢了，你走吧。"
		"一股阴冷的浓雾突然出现，很快地包围了你。"  ,
});
*/
virtual void create()
{
	set_name("白无常", "white gargoyle" );

	set("icon", masked_man);
	set("long","白无常伸著长长的舌头瞪著你，死白的脸上看不出任何喜怒哀乐。");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("age", 217);
	set("combat_exp", 20000);
	set("max_hp", 2700);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
}
NPC_END;
/*
	set("chat_msg", ({
		"白无常发出一阵像呻吟的声音，当他发现你正注视著他的时候，瞪了你一眼。",
			"白无常把长长的舌头伸出来，缓缓地舔了舔自己又白又长的手指。"
virtual void init(CChar *me)
{
	CNpc::init(me);
	if( !previous_object()
		||	!userp(previous_object())
		||	wizardp(previous_object()) ) return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(CChar * ob, int stage)
{
	int i;
	CChar * *inv, mailbox;
	if( !ob || !present(ob) ) return;
	
	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();
	
	inv =  all_inventory(ob);
	for (i = 0; i < sizeof(inv); i++)
		DROP_CMD->do_drop(ob, inv[i]);
	mailbox = load_item("/clone/misc/mailbox");
	mailbox->move(ob);
	ob->move(REVIVE_ROOM);
	message("vision",
		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里"
		"很久了，只是你一直没发觉。", ob->environment(), ob);
}
*/

