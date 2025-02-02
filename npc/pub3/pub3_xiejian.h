//xiejian.h  邪剑李四
//code by zwb
//12-25

NPC_BEGIN(CNpub3_xiejian);


virtual void create()
{
	
	set_name("李四","li si");
	
	set("icon", waiter);
	set("title", "小店老板");
	set("gender", "男性" );
	set("shen_type", -1);
	set("age", 40);
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	
	set("no_clean_up",1);
	
	set("long","这是整天笑咪咪的小店老板，虽然不卖什麽东西，却也过得自在。" );
	
	set("combat_exp", 50000);
	set("attitude", "peaceful");
	set("chat_chance", 1);
	
	set_inquiry("邪剑",ask_me);
	set_inquiry("杀人",ask_me);
	
	
	set("max_hp", 2100);
	set("mp", 700);
	set("max_mp", 700);
	set("mp_factor", 50);
	set("shen_type", -1);
	set("env/wimpy", 60);
	
	set_skill("force", 60); 
	set_skill("unarmed", 80);
	set_skill("sword", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	
	
	carry_object("gangjian")->wield();
//	carry_object("cloth")->wear();
}


virtual char * chat_msg(CChar * player)
{
	return " 这位客官，您想买些什麽东西吗 ?";
}

static char * ask_me(CNpc * npc , CChar  * player)
{
	return "我就是邪剑李四，你来找我有什麽事吗？";
}

/*
void init()
{
object me, ob;

  me = this_object();
  ob = this_player();
  
	::init();
	
	  if( !me->query("waiting_target") && ob->query_temp("fee_paid") ) 
	  ob->delete_temp("fee_paid");
	  
        add_action("do_name","杀");
		
		  }
		  
			string ask_me()
			{
			return "我就是邪剑李四，你来找我有什麽事吗？\n";
			}
			
			  int do_name(string target)
			  {
			  object me, dest, *all;
			  int i;
			  
				me = this_object();
				all = users();
				
				  if(me->query("waiting_target"))
				  return notify_fail("李四嘿嘿一笑：我现在正忙着哪，您呆会儿在来吧！\n");
				  
					if( !this_player()->query_temp("fee_paid") ) 
					return notify_fail("李四说道：不管叫我做什麽，您可得先付钱哪！\n");
					
					  if( !target || target==" ") 
					  return notify_fail("李四恶狠狠地说道：快告诉我那家伙的名字，我可没功夫听你闲聊！\n");
					  
						for(i=0; i<sizeof(all); i++) 
						{
						if( target == all[i]->name() || target == all[i]->id() )
						dest = all[i];
						}
						
						  if( !dest )
						  return notify_fail("李四一声冷笑：他现在不在游戏中，过会再来吧。\n");
						  
							if (dest->is_ghost())
							return notify_fail("李四很不高兴：他已经是个死鬼了，你还来找我干什么！\n");
							
							  write_file("/log/static/KILLRECORD",sprintf("%s   派李四去杀   %s on %s\n", this_player()->name(1),dest->name(1), ctime(time()) ));
							  me->set("waiting_target", dest->query("id"));
							  me->set("target_name", target);
							  
								me->set_temp("apply/attack",  50);
								me->set_temp("apply/defense", 50);
								me->set_temp("apply/damage",  20);
								
								  me->set("title", HIB "邪剑" NOR);
								  me->set("long",
								  "邪剑李四，杀手帮十大高级swordsman之一，有剑不染血不归鞘之名。\n" );
								  
									me->delete("chat_chance");
									me->delete("chat_msg");
									
									  message("vision",
									  HIY "李四嘿嘿嘿地干笑了几声，说道：您就在这儿静侯好音吧!\n"NOR,
									  environment(), me );
									  
										me->set("pursuer", 1);
										me->set("vendetta/authority", 1);
										me->set("bellicosity", 10000);
										me->set("combat_exp", 50000);
										
										  message_vision("$N走了出去。\n" NOR, me);
										  
											call_out("do_chase", 1, me);
											
											  return 1;
											  }
											  
												int accept_object(object who, object ob)
												{
												
												  if (ob->query("money_id") && ob->value() >= 1000000 
												  && !this_object()->query("waiting_target")) 
												  {
												  tell_object(who, "李四沉下脸来：好，爽快说吧，你要我帮你杀谁？\n");
												  tell_object(who, "请键入：杀 目标中文名字\n");
												  who->set_temp("fee_paid",1);
												  return 1;
												  }
												  else if (ob->query("money_id") && ob->value() < 1000000) 
												  {
												  tell_object(who, "李四嘿嘿一笑，说道：给我这麽多钱？ 将来我可没法还你啊。\n");
												  return 1;
												  }
												  
													return 0;
													}
													
													  int do_chase(object me)
													  {
													  
														object dest;
														dest = find_player(me->query("waiting_target"));
														
														  if( !objectp(dest) || !environment(dest) )	
														  {
														  call_out("waiting", 0, me);
														  return 1;
														  }
														  
															me->move(environment(dest));
															message_vision("$N走了过来。\n" NOR, me);
															me->set_leader(dest);
															command("look " + dest->query("id"));
															
															  if ( !environment(me)->query("no_fight"))
															  {
															  call_out("do_kill", 1, me, dest);
															  return 1;
															  }
															  else
															  {
															  call_out("waiting", 0, me);
															  return 1;
															  }
															  
																return 1;
																}
																
																  int do_kill(object me, object dest)
																  {
																  
																	if( objectp(dest) && present(dest, environment(me))
																	&& !environment(me)->query("no_fight"))
																	{
																	message_vision(HIR "$N对$n说道：阴司鬼王差我来，请你去他那儿做客，"
																	+RANK_D->query_rude(dest)+"，你认命吧！\n" NOR, me, dest);
																	me->set_leader(dest);
																	me->kill_ob(dest);
																	dest->fight_ob(me);
																	
																	  call_out("checking", 0,  me); 	
																	  }
																	  else  
																	  call_out("waiting", 1, me); 	
																	  
																		return 1;
																		}
																		
																		  int waiting(object me)
																		  {
																		  object dest;
																		  dest = find_player(me->query("waiting_target"));
																		  
																			if ( objectp(dest) )
																			{
																			if (dest->is_ghost())
																			{
																			me->delete("waiting_target");
																			call_out("do_back", 1, me);
																			return 1;
																			}else if (me->is_fighting() && present(dest, environment(me)))
																			{
																			call_out("checking", 0, me);
																			return 1;
																			}else if (living(me) && !environment(dest)->query("no_fight"))
																			{
																			call_out("do_chase", 0, me);
																			return 1;
																			}
																			}		
																			
																			  remove_call_out("waiting");
																			  call_out("waiting", 60, me);
																			  return 1;
																			  }
																			  
																				int checking(object me)
																				{
																				object ob;
																				
																				  if (me->is_fighting()) 
																				  {
																				  call_out("checking", 1, me);
																				  return 1;
																				  }
																				  
																					if( objectp(ob = present("corpse", environment(me)))
																					&& ob->query("victim_name") ==	me->query("target_name") )
																					{
																					me->delete("waiting_target");
																					call_out("do_back", 1, me);
																					return 1;
																					}
																					
																					  call_out("waiting", 0, me);
																					  return 1;
																					  }
																					  
																						int do_back(object me)
																						{
																						
																						  me->move("/d/village/shop");
																						  message("vision", "李四走了进来，拍了拍身上的尘土，把剑上的血迹抹拭干净，\n"
																						  "他接着一笑说道：老天爷保佑，活儿干得干净利落，您老以後有什麽事还可以找我。\n", 
																						  environment(), me );
																						  
																							me->set("title", "小店老板");
																							me->set("long",
																							"这是整天笑咪咪的小店老板，虽然不卖什麽东西，却也过得自在。\n" );
																							
																							  me->set_leader(0);
																							  me->set("chat_chance", 1);
																							  me->set("chat_msg", ({
																							  "李四说道: 这位客官，您想买些什麽东西吗 ?\n",
																							  }) );
																							  
																								return 1;
}*/

NPC_END;