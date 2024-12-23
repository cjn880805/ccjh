//laocai.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_laocai);

virtual void create()
{
	set_name("老财","laocai");

	set("icon", drugstore_boss);
	set("gender", "男性" );
	set("nickname","老财");
	set("age", 40);
	set("long", "一个有名的吝啬鬼，好象他整日看守着柴房也能发财似的。");
	set("shen_type",-1);
	set("combat_exp", 10000);
	set("str", 17);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("attitude", "friendly");
	carry_object("cloth")->wear();
	set_inquiry ("柴刀" ,  inquiry_dao  );
};

static char * inquiry_dao(CNpc * this_object, CChar * this_player)
{
	CContainer * ob;
	
	if (this_player->PresentName("chaidao",IS_ITEM))
		return "老材瞪着眼说：你身上带着一把，还想要！";

	ob=load_item("chaidao");
	ob->move(this_player);
	return "老材递给你一把柴刀，嘱咐道说：小心保管！";
}

NPC_END;
