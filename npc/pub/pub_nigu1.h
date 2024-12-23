NPC_BEGIN(CNPub_nigu1);

virtual void create()
{
	set_name("尼姑1","nigu");

	set("icon", young_nun);
	set("gender", "女性" );
	set("age", 22);
	set("long","这位尼姑正坐在铺垫上，双手捻着珠链，嘴中念念有词。");
	set("combat_exp", 1000);
	set("attitude", "friendly");

};
virtual char * greeting(CChar * me)
{
	static char msg[255];
	return snprintf(msg,255,"尼姑施了一礼说道：这位%s ，多谢捐赠，愿佛祖保佑。",query_respect(me));
}


NPC_END;
