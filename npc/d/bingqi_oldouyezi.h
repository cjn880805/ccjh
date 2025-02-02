//oldouyezi.h
//code by zwb
//12-16
//inherit F_CLEAN_UP;

NPC_BEGIN(CNBingQi_oldouyezi);


virtual void create()
{
		set_name("老欧冶子","ou ye zi");

        set("gender", "男性" );
        set("age", 73);
        set("long","欧冶子是当世铸剑大师。他铸的剑锋利无比。可是你给的钱太少可也不行。一分钱一分货么。");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("rank_info/respect", "欧冶师傅");
 	set("icon",old_man1);

        set_inquiry("铸剑","铸剑，好说，一百万金币，款到交货！");
        set_inquiry("价格","这个价格嘛...!嘿嘿,一律一百万起价，一分钱一分货么。");
		set("no_huan",1);
        
};


virtual int accept_object(CChar * player, CContainer * ob)
{
		char msg[255];

       if(player->query_temp("done_s"))
       {
          say(snprintf(msg,255,"欧冶子奇怪的看着%s道:你不是有自己的兵器吗？",player->name()),player);
		  SendMenu(player);
          return 0; 
	   }
       if( ob->query("money_id") && ob->query("value") >= 100000)
       {
			say(snprintf(msg,255," 好吧,%s我这就替你打造, 请稍等！",player->query("name")),player);

			message_vision("欧冶子将一块赤铜和一块青锡塞进炼炉，拉起沉重的风箱，火焰",player);
			message_vision("贪婪吞噬了铜锡块。..当铜锡块通体透红时欧冶子师傅将黑铁置入",player);
			message_vision("炉中，掺入黄金和白银。一会工夫，欧冶子用钢钳夹出五金块，猛地",player);
			message_vision("将它浸入一种无嗅无味的黑色液体中..唧！..",player);
			message_vision("随后..乒..乒..梆....梆....乒....乒...梆....梆...乒..梆....梆...乒...梆.....",player);
			message_vision("..哈....哈....哈....哈....欧冶子仰天长笑声震瓦铄，道：嘿..嘿.....",player);
			message_vision("宝剑有名方能传，你的宝剑该什么名(name)？!",player);

			player->query_temp("marks/ouyezi");
			player->set_temp("marks/ouyezi",1);
			add_money(ob->query("value"));
			return 1;
        }
	   return 0;
}


virtual int handle_action(char *comm, CChar * player, char * arg)
{
	if(comm == "name")
		return do_name(player, arg);

	return 0;
}

int do_name(CChar * player,char * arg)
{
		
		CContainer * ownsword;
		char msg[255];
		CChar *npc=(CChar *)this;

		if(!player->query_temp("marks/ouyezi"))
        {
            return notify_fail("欧冶子气得一甩手：什么？和我老人家也赖？");
        }

        if( !arg ) return notify_fail("欧冶子问道：宝剑有名方能传，你的宝剑该什么名(name)？");

        if( strlen(arg) > 20 )
			return notify_fail("欧冶子说：哇拷！这么长怎么写得下，想个短一点的吧！");


        ownsword= load_item("ownsword");
        ownsword->set_name(arg);
        npc->say(snprintf(msg,255,"只见欧冶子师傅抽出鱼肠剑，在宝剑上随手挥洒，立马就有了%s几个龙飞凤舞的细字，直把你看得目瞪口呆。",arg),player);		
        npc->say(" 成了。拿去吧！说完便递了一把剑过来..",player);

        ownsword->move(player);
        npc->say("你拿着剑端详一下，宝剑暗纹浮动，真是绝世无双的手艺。",player);
        player->query_temp("done_s");
        player->set_temp("done_s",1);
        player->delete_temp("marks/ouyezi");

		return 1;
}

NPC_END;
