// libanxian.h　李半仙
//zhangdongni  2001-07-18

NPC_BEGIN(CNcity_banxian);

virtual void create()
{
        set_name("李半仙", "li banxian" );
        set("long", "李半仙是个鹤发童颜的老人！乐于助人，你可以向他打听[减叛师]的情况。\n");
        set("nickname", "疯癫老头");
        set("attitude", "peaceful");
        set("combat_exp",600000);
        set("icon", old_man1);
        
        set("str",23);
        set("per",10);
        set("int",27);
        set("dex",17);
        set("con",17);
        
        set("hp", 6000);
	set("max_hp", 6000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
        
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force",200);
        set_skill("chanchu_bufa",200);
        set_skill("hamagong",200);
        set_skill("shexing_diaoshou",200);
        set_skill("lingshe_zhangfa",200);
        set_skill("staff",200);

        map_skill("dodge", "chanchu_bufa");
        map_skill("force", "hamagong");
        map_skill("parry", "lingshe_zhangfa");
        map_skill("unarmed", "shexing_diaoshou");
        map_skill("staff", "lingshe_zhangfa");
        
//      set_inquiry ("减叛师记录" ,"你找对人了，就是我能给你减判师记录(jian 判师记录)。\n",
        set_inquiry("叛师", "唉，后悔背叛师门了吧。");
        set_inquiry("叛师记录", "要是你以前曾经有过一次叛师师门的话，你的师傅可不愿意教你更高深的功夫！");
//                "减叛师"          :"你找对人了，就是我能给你减判师记录(jian 判师记录)。\n",
//              "减记录"          :"你找对人了，就是我能给你减判师记录(jian 判师记录)。\n",
  
/*
}
int accept_fight(object me)
{
        command("say 李半仙说：你还不配和我过招。");
        return 0;
}
void init()
{
        add_action("do_jian","jian");
}

int do_jian(string arg)
{
        object me;
        mapping my_skl;
        string *skl_name;
        int i,*level;
        me= this_player();
        if (arg != "叛师记录") 
                return notify_fail("你要减什么？\n");
        if (me->query("betrayer",) < 1) 
                return notify_fail("你叛过师么？\n");
       if ( me->query("banshi") > 2)
           {
               message_vision("你的叛师次数已经超过3次了！！\n", this_object(), me);
                   return 1;
           }

        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>1)
        		me->set_skill(skl_name[i],level[i]-1);
}
                  }
        message_vision(MAG"$N跪在了地上，开始忏悔背叛师门的往事，后悔呀。。。后悔。。。\n\n"NOR,me);
        me->set("combat_exp", me->query("combat_exp") - me->query("combat_exp") /10);
        me->add("betrayer",-1);
        me->add("banshi", 1);
//        me->add("banshi",1);
        me->set("title","普通百姓");
        me->set("class","0");
        me->delete("family");
        me->delete("party");
        me->start_busy(2);
        me->set("score",me->query("score") - me->query("score") /10);
        return 1;
}
*/

}
NPC_END;
