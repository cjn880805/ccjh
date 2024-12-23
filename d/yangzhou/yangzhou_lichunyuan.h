//lichunyuan.h

//Sample for room: 丽春院
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_lichunyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "丽春院");
	
	//add npcs into the room
	add_npc("pub_wei");
	add_npc("gaibang_kongkong");
	add_npc("pub_xiaogueizi");
	add_npc("pub_yantingyan");
	
	add_door("扬州东南", "扬州东南", "扬州丽春院");
	add_door("扬州丽春院二楼", "扬州丽春院二楼", "扬州丽春院");
	
};


void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && me->query("wei/renwu1") && !query("stop"))
	{
		CContainer * WeiNpc;
		CNpc * Wei_Npc;
		CContainer * env = me->environment();
		//////////////////////////////////////////////////
		WeiNpc=present("xiao guei zi");
		if(WeiNpc)
		{
			if(me->query_temp("wei/renwu2_5"))//建宇公主
			{
				WeiNpc=present("jian ning");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							//找回建宇公主
							me->set("wei/renwu2",1);
							me->add("wei/count",1);
							me->delete_temp("wei/renwu2_1");
							me->delete_temp("wei/renwu2_2");
							me->delete_temp("wei/renwu2_3");
							me->delete_temp("wei/renwu2_4");
							me->delete_temp("wei/renwu2_5");
							destruct(WeiNpc);
							Wei_Npc=load_npc("pub_jianning");
							((CChar *)Wei_Npc)->set("ok",1);
							((CChar *)Wei_Npc)->set("title",  "六鼎公夫人" );
							((CChar *)Wei_Npc)->move(env);
							
							tell_object(me, "\n$YEL建宇公主一把揪住小宝的耳朵道：“可终于找到你了！说，我不在的时候是不是出去找到第八个老婆了？”\n");   
							tell_object(me, "$YEL你看得背脊一凉，侧身从疼得龇牙咧嘴的小宝身边溜过准备悄悄离开，却发现手头已多了一张小宝塞给你的银票。\n");   
							load_item("yinpiao")->move(me);
						}			
					}
				}
			}
			//////////////////////////////////////////////////
			if(me->query_temp("wei/renwu3_9"))//阿可
			{
				WeiNpc=present("a ke");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							//找回阿可
							me->set("wei/renwu3",1);
							me->add("wei/count",1);
							me->delete_temp("wei/renwu3_1");
							me->delete_temp("wei/renwu3_2");
							me->delete_temp("wei/renwu3_3");
							me->delete_temp("wei/renwu3_4");
							me->delete_temp("wei/renwu3_5");
							me->delete_temp("wei/renwu3_6");
							me->delete_temp("wei/renwu3_7");
							me->delete_temp("wei/renwu3_8");
							me->delete_temp("wei/renwu3_9");
							destruct(WeiNpc);
							Wei_Npc=load_npc("wei_ake");
							((CChar *)Wei_Npc)->set("ok",1);
							((CChar *)Wei_Npc)->set("title",  "六鼎公夫人" );
							((CChar *)Wei_Npc)->move(env);
							
							tell_object(me, "\n$YEL小宝看着阿可憔悴的脸，心疼地一把把阿可搂在怀里：好阿可，这些日子可苦了你了！走，咱们先回扬州好好休息一阵吧！");   
							tell_object(me, "\n$YEL你帮小宝找回了阿可，江湖阅历增加了3000点经验。");   
							me->add("combat_exp",3000);
							me->UpdateMe();
						}			
					}
				}
			}
			//////////////////////////////////////////////////
			if(me->query_temp("wei/renwu4_8"))//苏情
			{
				WeiNpc=present("su quan");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							//找回苏情
							me->set("wei/renwu4",1);
							me->add("wei/count",1);
							me->delete_temp("wei/renwu4_1");
							me->delete_temp("wei/renwu4_2");
							me->delete_temp("wei/renwu4_3");
							me->delete_temp("wei/renwu4_4");
							me->delete_temp("wei/renwu4_5");
							me->delete_temp("wei/renwu4_6");
							me->delete_temp("wei/renwu4_7");
							me->delete_temp("wei/renwu4_8");
							destruct(WeiNpc);
							Wei_Npc=load_npc("wei_su");
							((CChar *)Wei_Npc)->set("ok",1);
							((CChar *)Wei_Npc)->move(env);
							
							tell_object(me, "\n$YEL苏情看着眼前这个武功年龄都不及自己的男人，心里却是前所未有的放松。");   
							tell_object(me, "$YEL苏情疲惫地坐了下来，向小宝道：“我好累呀！”");   
							tell_object(me, "$YEL小宝赶紧端了一杯热茶给苏情，然后转到身后轻轻为她揉肩捶背！");   
							tell_object(me, "\n$YEL小宝向你挤了挤眼睛，顺着他的眼光看去，只见茶盘下面露出银票的一角！");   
							load_item("yinpiao")->move(me);
						}			
					}
				}
			}
			//////////////////////////////////////////////////
			if(me->query_temp("wei/renwu5_18"))//沐剑萍
			{
				WeiNpc=me->present("mujian ping");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							//找回沐剑萍
							me->set("wei/renwu5",1);
							me->add("wei/count",1);
							me->delete_temp("wei/renwu5_1");
							me->delete_temp("wei/renwu5_2");
							me->delete_temp("wei/renwu5_3");
							me->delete_temp("wei/renwu5_4");
							me->delete_temp("wei/renwu5_5");
							me->delete_temp("wei/renwu5_6");
							me->delete_temp("wei/renwu5_7");
							me->delete_temp("wei/renwu5_8");
							me->delete_temp("wei/renwu5_9");
							me->delete_temp("wei/renwu5_10");
							me->delete_temp("wei/renwu5_11");
							me->delete_temp("wei/renwu5_12");
							me->delete_temp("wei/renwu5_13");
							me->delete_temp("wei/renwu5_14");
							me->delete_temp("wei/renwu5_15");
							me->delete_temp("wei/renwu5_16");
							me->delete_temp("wei/renwu5_17");
							me->delete_temp("wei/renwu5_18");
							me->delete_temp("wei/renwu5_time");
							destruct(WeiNpc);
							Wei_Npc=load_npc("wei_mujianping");
							((CChar *)Wei_Npc)->set("ok",1);
							((CChar *)Wei_Npc)->set("title",  "六鼎公夫人" );
							((CChar *)Wei_Npc)->move(env);
							
							tell_object(me, "\n$YEL你气喘吁吁的大声呼道：“宝公公，快扶一下，人晕过去了，不过没有大碍。”");   
							tell_object(me, "$YEL小宝心疼的从你怀中抱起了沐剑萍，匆匆安置后就准备进宫找太医去，临行前还连声对你道谢。");   
							tell_object(me, "\n$YEL你帮小宝找回了沐剑萍，江湖阅历增加了3000点经验。");   
							me->add("combat_exp",3000);
							me->UpdateMe();
						}			
					}
				}
			}
			//////////////////////////////////////////////////
			if(me->query_temp("wei/renwu6_9"))//方瑜
			{
				WeiNpc=present("fang yu");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							
							if(!me->query("wei/renwu7")|| (me->query("wei/renwu7") && me->query_temp("wei/renwu6_8")))
							{
								me->set("wei/renwu6",1);//找回方瑜
								me->add("wei/count",1);
								destruct(WeiNpc);
								Wei_Npc=load_npc("wei_fang");
								((CChar *)Wei_Npc)->set("ok",1);
								((CChar *)Wei_Npc)->set("title",  "六鼎公夫人" );
								((CChar *)Wei_Npc)->move(env);
								
								tell_object(me, "\n$YEL小宝悄悄从后面一把抱住方瑜，贼溜溜地笑道：“好老婆你可回来了，来亲一个先！”");   
								tell_object(me, "$YEL方瑜红着脸佯怒道：“你少来，快走开！！”");   
																
								tell_object(me, "\n$YEL你帮小宝找回了方瑜，江湖阅历增加了3000点经验。");   
								me->add("combat_exp",3000);
								me->UpdateMe();
							}
							else
							{
								tell_object(me, "\n$YEL方瑜满脸惊讶地看着曾雪颈间的玉佩。");   
								tell_object(me, "$YEL方瑜与曾雪发生了争执。");   
								tell_object(me, "$YEL曾雪将玉佩丢弃在地，含着泪跑开了。");   
								tell_object(me, "$YEL方瑜拾起玉佩，细细地擦拭干净，拿绢帕包了起来，然后转身离开了。\n");   
								
								tell_object(me, "\n$YEL你弄巧成拙，满面尴尬，江湖阅历降低了2800点经验。");   
								me->add("combat_exp",-2800);
								me->add("wei/count",-1);
								me->UpdateMe();
								me->del("wei/renwu7");
								destruct(WeiNpc);
								WeiNpc=present("zeng rou");
								if(WeiNpc)
								{
									destruct(WeiNpc);
								}
							}
							me->delete_temp("wei/renwu6_1");
							me->delete_temp("wei/renwu6_2");
							me->delete_temp("wei/renwu6_3");
							me->delete_temp("wei/renwu6_4");
							me->delete_temp("wei/renwu6_5");
							me->delete_temp("wei/renwu6_6");
							me->delete_temp("wei/renwu6_7");
							if(!me->query_temp("wei/renwu7_10"))
								me->delete_temp("wei/renwu6_8");
							me->delete_temp("wei/renwu6_9");							
							me->delete_temp("wei/renwu6_10");
							
							me->delete_temp("wei/renwu8_1");
							me->delete_temp("wei/renwu8_2");
							me->delete_temp("wei/renwu8_3");
							me->delete_temp("wei/renwu8_4");
							me->delete_temp("wei/renwu8_5");
							me->delete_temp("wei/renwu8_6");
							me->delete_temp("wei/renwu8_7");
							me->delete_temp("wei/renwu8_8");
							me->delete_temp("wei/renwu8_9");
							me->delete_temp("wei/renwu8_10");
							me->delete_temp("wei/renwu8_11");
							me->delete_temp("wei/renwu8_12");
						}			
					}
				}
			}
			//////////////////////////////////////////////////
			if(me->query_temp("wei/renwu7_10"))//曾雪
			{
				WeiNpc=present("zeng rou");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							if(!me->query("wei/renwu6")|| (me->query("wei/renwu6") && me->query_temp("wei/renwu6_8")))
							{
								me->set("wei/renwu7",1);//找回曾雪
								me->add("wei/count",1);
								destruct(WeiNpc);
								Wei_Npc=load_npc("wei_zengrou");
								((CChar *)Wei_Npc)->set("ok",1);
								((CChar *)Wei_Npc)->set("title",  "六鼎公夫人" );
								((CChar *)Wei_Npc)->move(env);
								
								tell_object(me, "\n$YEL曾雪手腕一转，把一个大骰子丢到小宝面前的桌上，只见骰子骨碌碌飞快地转了起来。");   
								tell_object(me, "$YEL曾雪得意地对小宝说道：“猜猜是几点？”");   
								tell_object(me, "$YEL小宝抚掌大笑道：“有趣有趣，这下有对手可以陪我玩了！”");   
								
								tell_object(me, "\n$YEL你帮小宝找回了曾雪，江湖阅历增加了2800点经验。");   
								me->add("combat_exp",2800);
								me->UpdateMe();
							}
							else
							{
								tell_object(me, "\n$YEL方瑜满脸惊讶地看着曾雪颈间的玉佩。");   
								tell_object(me, "$YEL方瑜与曾雪发生了争执。");   
								tell_object(me, "$YEL曾雪将玉佩丢弃在地，含着泪跑开了。");   
								tell_object(me, "$YEL方瑜拾起玉佩，细细地擦拭干净，拿绢帕包了起来，然后转身离开了。\n");   
								
								tell_object(me, "\n$YEL你弄巧成拙，满面尴尬，江湖阅历降低了3000点经验。");   
								me->add("combat_exp",-3000);
								me->add("wei/count",-1);
								me->UpdateMe();
								me->del("wei/renwu6");
								destruct(WeiNpc);
								WeiNpc=present("fang yu");
								if(WeiNpc)
								{
									destruct(WeiNpc);
								}
							}
							me->delete_temp("wei/renwu7_1");
							me->delete_temp("wei/renwu7_2");
							me->delete_temp("wei/renwu7_3");
							me->delete_temp("wei/renwu7_4");
							me->delete_temp("wei/renwu7_5");
							me->delete_temp("wei/renwu7_6");
							me->delete_temp("wei/renwu7_7");
							me->delete_temp("wei/renwu7_8");
							me->delete_temp("wei/renwu7_9");
							me->delete_temp("wei/renwu7_10");
							
							me->delete_temp("wei/renwu8_1");
							me->delete_temp("wei/renwu8_2");
							me->delete_temp("wei/renwu8_3");
							me->delete_temp("wei/renwu8_4");
							me->delete_temp("wei/renwu8_5");
							me->delete_temp("wei/renwu8_6");
							me->delete_temp("wei/renwu8_7");
							me->delete_temp("wei/renwu8_8");
							me->delete_temp("wei/renwu8_9");
							me->delete_temp("wei/renwu8_10");
							me->delete_temp("wei/renwu8_11");
							me->delete_temp("wei/renwu8_12");

							me->delete_temp("wei/renwu6_8");
						}			
					}
				}
			}
			//////////////////////////////////////////////////
			if(me->query_temp("wei/renwu9_4"))//霜儿
			{
				WeiNpc=present("shuang er");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							if(!me->query("wei/renwu9"))
							{
								tell_object(me, "\n$YEL霜儿走了过来。");   
								tell_object(me, "$YEL霜儿越想越伤心，终于忍不住趴在小宝的肩膀上放声大哭起来。");  
								tell_object(me, "\n$HIR你得到了10点实战经验的奖励。");  
								me->add("combat_exp",10);
								me->UpdateMe();
								if(me->query("wei/count")!=6 )
								{
									tell_object(me, "\n$YEL霜儿捧起小宝的脸，仔仔细细地看了看。");   
									tell_object(me, "$YEL霜儿抡起手“啪”的一巴掌打在小宝脸上！");   
									tell_object(me, "$YEL霜儿气呼呼的跑了。");  
									destruct(WeiNpc);
								}
								else
								{
									me->set("wei/renwu9",1);//找回霜儿
									me->add("wei/count",1);
									destruct(WeiNpc);
									/*
									Wei_Npc=load_npc("wei_shuanger");
									((CChar *)Wei_Npc)->set("ok",1);
									((CChar *)Wei_Npc)->set("title",  "六鼎公夫人" );
									((CChar *)Wei_Npc)->move(env);
									*/
									tell_object(me, "\n$YEL小宝捧起霜儿的脸，给了她无限温柔的一个吻，“大功告成，亲个嘴儿”。");   
									
									tell_object(me, "\n$YEL小宝抱着双儿的同时也不望塞给你个红包，你打开一看，竟然是张十万两的银票！");   
									CContainer * bot = load_item("yinpiao1");
									bot->set("value",100000);
									bot->move(me);
									
									char msg[255];
									g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s弟子%s(%s)$HIY行走江湖不忘成人之美，展现侠骨柔肠，热心替小宝找回七位如花似玉妻子。$COM",  me->querystr("family/family_name"),me->name(1),me->id(1)));

									tell_object(me, "\n$YEL何芳芳带着一群穿红带绿的老大娘将霜儿等七女围了起来，给她们换上了新娘大红礼服。");   
									
									g_Channel.do_channel(&g_Channel, 0, "news", "\n\n                         $HIW小宝的婚礼开始了！\n               锣鼓叮叮咚咚地敲起，吉祥的唢呐吹出了喜庆与欢乐的音乐。\n          一大群人簇拥着晕晕呼呼的小宝和七个千娇百媚的新娘走上大堂正中。\n\n");
									g_Channel.do_channel(&g_Channel, 0, "news", "$HIW\n\n                    只听主婚人空空儿高喊一声：一拜天地！\n                何小宝当先对着大门咕咚跪下，瞌了个响头！\n          七位新娘扭扭捏捏地互相推搡了一阵子，终于一起盈盈拜了下去！\n\n");
									g_Channel.do_channel(&g_Channel, 0, "news", "$HIW\n\n                    主婚人空空儿高喊一声：二拜高堂！\n                小宝拉着七个新娘一起向着何芳芳拜了下去。\n                直乐得何芳芳直叫“乖仔，好媳妇”！\n\n");
									g_Channel.do_channel(&g_Channel, 0, "news", "$HIW\n\n                    主婚人空空儿高喊一声：夫妻对拜！\n                 七个新娘都只向着着何小宝略一欠身示意。\n             小宝却又咕呼一声跪下，向着七位老婆一一行拜礼。\n\n");
									g_Channel.do_channel(&g_Channel, 0, "news", "$HIW\n\n                    最后，随着空空儿高喊：送入洞房！\n       喜滋滋的小宝牵起了红绸的一头，带着七个羞答答的新娘一同进入了内堂！\n\n");

									//发礼物
									MAP2USER * user;
									iterator_user p;
									CUser * obj;
									user = users();
									for ( p=user->begin(); p!=user->end(); p++)
									{
										obj = p->second;
										char msg[255];
										CContainer * gift;
										
										snprintf(msg, 255, "天上飘扬着落下一个袋子，不偏不倚落在你的怀中……\n你打开一看，看到了一张喜帖，一瓶酒和一块蛋糕。");
										tell_object(obj,msg);
										
										gift=load_item("cake");
										gift->move(obj);
										
										if (EQUALSTR(obj->querystr("gender"), "男性"))	//竹叶青
										{
											gift=load_item("jiuping2");
											gift->move(obj);
										}
										
										if (EQUALSTR(obj->querystr("gender"), "女性"))	//女儿红
										{
											gift=load_item("nverhong");
											gift->move(obj);
										}
										
										if (EQUALSTR(obj->querystr("gender"), "无性"))	//壮阳酒
										{
											gift=load_item("jiuping");
											gift->move(obj);
										}
										
										gift=load_item("baozi");
										gift->set_name("小宝与七位娇妻的喜帖", "xi tie");
										gift->set("value",0l);
										gift->set("long","这是一张小宝与七位娇妻的喜帖。");
										gift->set("unit","张");
										gift->move(obj);

										CContainer * env = load_room("pk");
										if(env->query("happy"))		//新年活动
										{
											if(obj->query("level")>30 && obj->query("combat_exp")>81000 &&
												obj->query_skill("force", 1) > 60 && obj->query_skill("dodge", 1) >60 
												&& obj->query_skill("parry", 1) >60 && obj->query_skill("literate", 1) >60)
											{
												gift=load_item("dazongzi");
												if(random(100)>80 )
													gift->set("宝贝",1);
												gift->move(obj);
												snprintf(msg, 255, "你意外的发现你的手中还有一个香喷喷的肉粽子。");
												tell_object(obj,msg);
											}
										}
									}
									
									tell_object(me, "\n$YEL何芳芳手捧着一个大红包裹走到你跟前！");   
									tell_object(me, snprintf(msg, 255, "$YEL何芳芳说道：“我那宝贝仔今天能成亲，全亏了%s相助，这点点小意思，就请收下吧！”",query_respect(me)));   
									tell_object(me, "\n$YEL何芳芳给了你一个大红包裹。");   
									bot = load_item("baoguo1");
									bot->set("owner", me->id(1));
									bot->move(me);

									//if((query("count")%10)==8)
									if(random(10)==0)
									{
										switch(random(5))
										{
										case 0:
											bot=load_item("chunjie_ts");
											tell_object(me, snprintf(msg, 255,"\n$YEL何芳芳想了一想，又说道：“上次一个酸秀才丢了一本破书在这里，我也不知道是做什么，不如也一起送给%s吧，也许%s用的上呢！”",query_respect(me),query_respect(me))); 
											tell_object(me, "\n$YEL何芳芳递给了你一本「唐诗三百首」。"); 
											break;
										case 1:
											bot=load_item("cunyang_sword");
											tell_object(me, snprintf(msg, 255,"\n$YEL何芳芳想了一想，又说道：“上次一个臭道士留给我一把破剑，说什么可以守正辟邪，我一个老娘们又不出门打打杀杀，要它也没什么用，不如也一起送给%s吧，也许%s用的上呢！”",query_respect(me),query_respect(me))); 
											tell_object(me, "\n$YEL何芳芳递给了你一把「纯阳剑」。"); 
											break;
										case 2:
											bot=load_item("zihulu");
											tell_object(me, snprintf(msg, 255,"\n$YEL何芳芳想了一想，又说道：“上次一个脏兮兮的乞丐丢了一个破葫芦在这里，好象还装了些酒，鬼知道还能不能喝了，如果%s不嫌弃的话，那我就拿给%s出门用吧！”",query_respect(me),query_respect(me))); 
											tell_object(me, "\n$YEL何芳芳递给了你一个「小紫葫芦」。"); 
											break;
										case 3:
											bot=load_item("dazongzi");
											tell_object(me, snprintf(msg, 255,"\n$YEL何芳芳想了一想，又说道：“前几天姑娘们买了一些粽子，好象还有几个剩下没吃完的，不知道馊了没，如果%s不介意的话，那%s就拿一个吧！”",query_respect(me),query_respect(me))); 
											tell_object(me, "\n$YEL何芳芳递给了你一个「粽子」。"); 
											break;
										case 4:
											bot=load_item("huanchunwan");
											tell_object(me, snprintf(msg, 255,"\n$YEL何芳芳想了一想，又说道：“我这里还有几颗自制的药丸，今天觉得和%s投缘，就送%s一颗吧！”",query_respect(me),query_respect(me))); 
											tell_object(me, "\n$YEL何芳芳递给了你一颗「还春丸」。"); 
											break;
										}
										bot->set("ok",1);
										bot->move(me);
									}

									if(me->query("disfigurement"))//修复之前使用道具造成的毁容记录
									{
										tell_object(me, snprintf(msg, 255,"\n$YEL何芳芳仔细端详着你伤痕累累的面孔，“哟，这位%s，这么俊秀的脸上怎么也受了伤呀！”。",query_respect(me)));  
										tell_object(me, "$YEL何芳芳从口袋中拿出一盒膏药，二话不说，就给你抹了上去");  
										tell_object(me, "$YEL你只觉得脸上凉飕飕的，定睛一看，不由的大吃一惊，原来何芳芳手中拿的竟是一盒「蜜丽疤痕灵」。\n");  
										tell_object(me, "$HIR你的容貌恢复了。\n");  
										int per_pro=38-me->query("disfigurement");
										if(me->query("per")<=per_pro)
											me->add("per",me->query("disfigurement"));
										me->del("disfigurement");
									}

									//((CChar *)Wei_Npc)->move(load_room("temp"));
									//WeiNpc->move(load_room("temp_xb"));
									me->del("wei");
									me->delete_temp("wei");
									me->add("xkd/wei",1);
									
								}
								me->delete_temp("wei/renwu9_1");
								me->delete_temp("wei/renwu9_2");
								me->delete_temp("wei/renwu9_3");
								me->delete_temp("wei/renwu9_4");
							}
						}			
					}
				}
			}
			//////////////////////////////////////////////////
		}
	}
}

int g_player()
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
		char msg[255];
		CContainer * gift;

		snprintf(msg, 255, "天上飘扬着落下一个袋子，不偏不倚落在你的怀中……\n你打开一看，看到了一张喜帖，一瓶酒和一块蛋糕。");
        tell_object(obj,msg);

		gift=load_item("cake");
		gift->move(obj);

		if (EQUALSTR(obj->querystr("gender"), "男性"))	//竹叶青
		{
			gift=load_item("jiuping2");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "女性"))	//女儿红
		{
			gift=load_item("nverhong");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "无性"))	//壮阳酒
		{
			gift=load_item("jiuping");
			gift->move(obj);
		}

		gift=load_item("anmenkey");
		gift->set_name("小宝与七位娇妻的喜帖", "xi tie");
		gift->set("value",0l);
		gift->set("long","这是一张小宝与七位娇妻的喜帖。");
		gift->set("unit","张");
		gift->move(obj);
    }
    
	return 1;
}

ROOM_END;
