NPC_BEGIN(CNPub_nigu2);

virtual void create()
{
	set_name("尼姑","nigu2");
	
	set("icon", young_nun);
	set("gender", "女性" );
	set("age", 32);
	set("long","这位尼姑正坐在铺垫上，双手捻着珠链，嘴中念念有词。 ");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	
	
};
virtual char * greeting(CChar * me)
{
	static char msg[255];
	return snprintf(msg,255,"尼姑施了一礼说道：这位%s 佛家人慈善为本，捐一点银两吧。",query_respect(me));
}


NPC_END;
