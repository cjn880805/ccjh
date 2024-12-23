//pub_xiaogueizi.h
//秦波 2002-12-09

NPC_BEGIN(CNpub_xiaogueizi);

virtual void create()
{
	set_name("何小宝", "xiao guei zi");
	//	set("long", "他一身飘逸的白色长衫，手摇折扇，风流儒雅。");
	set("title", "六鼎公");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("per", 30);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);
	
	set("hp", 6500);
	set("max_hp", 6500);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 10);
	
	set("combat_exp", 400000);
	set("score", 40000);

    set_skill("literate", 1);
	set_skill("force", 10);
	set_skill("dodge", 200);
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("whip", 10);
	set_skill("blade", 10);
	set_skill("sword", 10);
	set_skill("hand", 10);
	set_skill("claw", 10);
	set_skill("houquan", 10);
	set_skill("yunlong_xinfa", 10);
	set_skill("yunlong_shengong", 10);
	set_skill("wuhu_duanmendao", 10);
	set_skill("yunlong_jian", 10);
	set_skill("yunlong_shenfa", 10);
	set_skill("yunlong_bian", 10);
	set_skill("yunlong_shou", 10);
	set_skill("yunlong_zhua", 10);
	
	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu_duanmendao");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");
	
	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");

	create_family("云龙门",2,"弟子");
	
	set("chat_chance", 3);
	
	add_money(1000);
	set("no_talk",1);
};

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "小宝唱道:“冻风有信，秋月无边，亏我思娇的情绪好比度日如年......”";
	case 1:
		random_move();
		return 0;
	case 2:
		return "小宝唱道:“虽则我不是玉树临风，潇洒倜傥，但是我有广阔的胸襟和强劲的臂弯！”";
	}
	
	return 0;
}


int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("wei/renwu1"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("向小宝打听他的七个老婆", "dating",me);	
			AddMenuItem("向小宝打听帮忙找老婆", "help",me);
			if(me->query_temp("wei/renwu9_1"))
			{
				AddMenuItem("向小宝打听霜儿的事", "shuanger",me);
			}
			if(me->query("wei/count")==7)
			{
				AddMenuItem("向小宝领取找老婆的奖励", "jiangli",me);
			}
			SendMenu(me);
		}
		else if(!strcmp(ask, "dating") )
		{
			say( "我老娘老是问我，丽春院里那么多姑娘，为什么非要的她们七个！",me);   
			say( "她哪里知道，我那七个老婆虽然性格各异，但个个都是举世无双的美女，奇女，丽春院里的那些姑娘，哪里能及她们的万分之一呀！",me);   
			say( "小宝掰起指头一个个数道：霜儿最会疼人；阿可最靓；建宇虽然有些公主脾气，但最听话；苏情最迷人；沐刀萍最可爱；方瑜热起来像火，冷起来似冰；曾雪最让人摸不透，却又仍不住想要对她更了解。",me);   
			me->set_temp("wei/renwu1_2",1);
			SendMenu(me);
		}
		else if(!strcmp(ask, "shuanger") )
		{
			say( "小宝说道：霜儿呀，就只知道疼我！",me);   
			if(!me->query_temp("wei/renwu9_2"))
			{
				say( "小宝拿出一张纸来，拿手笔在上面画了几笔，然后递给了你。",me);   
				me->set_temp("wei/renwu9_2",1);//拿到小宝墨宝
				CContainer * hua=load_item("redrose");
				hua->set_name( "小宝墨宝","xiaobao hua");
				hua->set("long","这是一幅毛笔画的人物画，虽然画工极其拙劣，但仍可以看出，一个长辫子的男人，躺在一张床上，似乎是得了什么病的模样。");
				hua->move(me);
			}
			SendMenu(me);
		}
		else if(!strcmp(ask, "help") )
		{
			if(!me->query("wei/count"))
			{
				if(!me->query_temp("wei/renwu1_2"))
				{
					tell_object(me, "$YEL小宝惊讶地“啊”了一声！\n");   
					tell_object(me, "小宝奇怪地向你问道：“你认识我那些老婆吗？”");   
				}
				else
				{
					tell_object(me, "$YEL小宝高兴得跳了起来！\n");   
					tell_object(me, "小宝高兴的说道:“太好了，你要是帮我找回了老婆，我一定好好谢谢你！”");   
					me->set("wei/renwu1",1);
				}
			}
			else
			{
				char msg[255];
				tell_object(me, "$YEL小宝拍了拍你的肩膀，一付好小子，好好干的样子！\n");   
				tell_object(me, snprintf(msg, 255,"你已经帮我找到了%d个老婆，如果你能帮我找到其他老婆，我一定重重酬谢你。",me->query("wei/count")));   
				me->set("wei/renwu1",1);
			}
		}
		else if(!strcmp(ask, "jiangli") )
		{
			//领取最终奖励
			say( "我程序都没写完，你怎么可能领的到呢？",me); 
			SendMenu(me);
		}
		return 1;
	}
	return CNpc::do_talk(me, ask);
}

virtual void die()
{
	CContainer * env = load_room("扬州丽春院");
	if(env->query("小宝"))
	{
		env->del("小宝");
	}
	CNpc::die();
}
NPC_END;
