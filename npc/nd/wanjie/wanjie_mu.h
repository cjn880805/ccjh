// mu.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNwanjie_mu);

virtual void create()
{
        set_name("木婉青", "mu wanqing");
        set("gender", "女性" );
        set("age", 17);
        set("str", 26);
        set("con", 24);
        set("dex", 21);
        set("per", 28);
        set("int", 27);
        set("icon",young_woman10);
        set("long",
		"一张脸秀丽绝俗，如新月清晖，如花树堆雪。\n"
		"看上去楚楚可怜，娇柔婉转。只是长时间面幕\n"
		"脸之故，脸色苍白，没半点血色，两片薄薄的\n"
		"嘴唇，也是血色极淡。\n");

        set("attitude", "friendly");

	set_inquiry("誉儿"," 段哥哥呢？他在哪儿？说完，木婉清的脸上现出一丝红晕。 ");
	set_inquiry("中灵"," 钟灵这死丫头，哼！ ");
	set_inquiry("木婉青"," 我就是木婉清。 ");

        set("max_mp", 600);
        set("mp", 600);
        set("mp_factor" , 50);
        set("combat_exp", 550000);
	set("shen_type", 0l);

        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("sun_finger",100);
        set_skill("yizhi_chan",100);

        map_skill("finger", "sun_finger");
        map_skill("parry", "sun_finger");

//	carry_object("pink_dress")->wear();
//	carry_object("shoes")->wear();
}
/*
int accept_object(object who, object ob)
{
        if (ob->name() == "绝情花") {
           message_vision("$N拿出一朵绝情花给木婉清。\n",who);
           call_out("do_give", 1, who );
           return 1;
        }
        return 0;
}

void do_give(object me)
{
        object room = find_object(__DIR__"backyard");
        object who;

        message_vision("木婉清将绝情花吃了下去，她中的「阴阳合和散」的药性解除了！\n",me);
        command("say 太谢谢了，我这就要离开这是非之地，后会有期！");
        message_vision("木婉清取出一根彩菱往外一抛，身影如风一般飞了出去。\n",me);
        message_vision("只听外面脚步声渐渐远去，又有人追了过去。\n", me);
        me->add("combat_exp",random(60)+ 20 );
        me->add("potential",random(30) + 20);

        destruct( this_object() );
}
*/
NPC_END;