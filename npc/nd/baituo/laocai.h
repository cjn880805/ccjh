// laocai.h 　老财
//zhangdongni  2001-07-18


NPC_BEGIN(CNbiatuo_laocai);

virtual void create()
{
	set_name("老材", "lao cai" );
	set("gender", "男性" );
	set("nickname","老财");
	set("age", 40);
	set("long", "一个有名的吝啬鬼，好象他整日看守着柴房也能发财似的。\n");
	set("shen_type",-1);
	set("combat_exp", 10000);
	set("str", 30);
	set("dex", 28);
	set("con", 22);
	set("int", 24);
	set("attitude", "friendly");
	set("icon", young_man1);
	set_inquiry("柴刀", "你身上带着一把,还想要！");
	
//	     carry_object("cloth")->wear();

/*
}

string inquiry_dao()
{
 object me=this_player();
 object ob;

 if (present("chai dao",me))
  return "老材瞪着眼说：你身上带着一把，还想要！\n";
 else
 {
 ob=new("/d/baituo/obj/chaidao");
 ob->move(me);
  return "老材递给你一把柴刀，嘱咐道说：小心保管！\n";
 }
}
*/

}

NPC_END;