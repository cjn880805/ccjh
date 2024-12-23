//lichunyuan.h

//Sample for room: ����Ժ
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_lichunyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ժ");
	
	//add npcs into the room
	add_npc("pub_wei");
	add_npc("gaibang_kongkong");
	add_npc("pub_xiaogueizi");
	add_npc("pub_yantingyan");
	
	add_door("���ݶ���", "���ݶ���", "��������Ժ");
	add_door("��������Ժ��¥", "��������Ժ��¥", "��������Ժ");
	
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
			if(me->query_temp("wei/renwu2_5"))//�����
			{
				WeiNpc=present("jian ning");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							//�һؽ����
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
							((CChar *)Wei_Npc)->set("title",  "����������" );
							((CChar *)Wei_Npc)->move(env);
							
							tell_object(me, "\n$YEL�����һ�Ѿ�סС���Ķ���������������ҵ����ˣ�˵���Ҳ��ڵ�ʱ���ǲ��ǳ�ȥ�ҵ��ڰ˸������ˣ���\n");   
							tell_object(me, "$YEL�㿴�ñ���һ����������۵����������С��������׼�������뿪��ȴ������ͷ�Ѷ���һ��С�����������Ʊ��\n");   
							load_item("yinpiao")->move(me);
						}			
					}
				}
			}
			//////////////////////////////////////////////////
			if(me->query_temp("wei/renwu3_9"))//����
			{
				WeiNpc=present("a ke");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							//�һذ���
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
							((CChar *)Wei_Npc)->set("title",  "����������" );
							((CChar *)Wei_Npc)->move(env);
							
							tell_object(me, "\n$YELС�����Ű����㲵��������۵�һ�ѰѰ���§�ڻ���ð��ɣ���Щ���ӿɿ������ˣ��ߣ������Ȼ����ݺú���Ϣһ��ɣ�");   
							tell_object(me, "\n$YEL���С���һ��˰��ɣ���������������3000�㾭�顣");   
							me->add("combat_exp",3000);
							me->UpdateMe();
						}			
					}
				}
			}
			//////////////////////////////////////////////////
			if(me->query_temp("wei/renwu4_8"))//����
			{
				WeiNpc=present("su quan");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							//�һ�����
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
							
							tell_object(me, "\n$YEL���鿴����ǰ����书���䶼�����Լ������ˣ�����ȴ��ǰ��δ�еķ��ɡ�");   
							tell_object(me, "$YEL����ƣ����������������С���������Һ���ѽ����");   
							tell_object(me, "$YELС���Ͻ�����һ���Ȳ�����飬Ȼ��ת���������Ϊ����紷����");   
							tell_object(me, "\n$YELС�����㼷�˼��۾���˳�������۹⿴ȥ��ֻ����������¶����Ʊ��һ�ǣ�");   
							load_item("yinpiao")->move(me);
						}			
					}
				}
			}
			//////////////////////////////////////////////////
			if(me->query_temp("wei/renwu5_18"))//�彣Ƽ
			{
				WeiNpc=me->present("mujian ping");
				if(WeiNpc)
				{
					if(WeiNpc->querystr("owner")[0])
					{
						if(EQUALSTR(WeiNpc->querystr("owner"),me->id(1)))
						{
							//�һ��彣Ƽ
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
							((CChar *)Wei_Npc)->set("title",  "����������" );
							((CChar *)Wei_Npc)->move(env);
							
							tell_object(me, "\n$YEL�����������Ĵ����������������������һ�£����ι�ȥ�ˣ�����û�д󰭡���");   
							tell_object(me, "$YELС�����۵Ĵ��㻳�б������彣Ƽ���ҴҰ��ú��׼��������̫ҽȥ������ǰ�����������л��");   
							tell_object(me, "\n$YEL���С���һ����彣Ƽ����������������3000�㾭�顣");   
							me->add("combat_exp",3000);
							me->UpdateMe();
						}			
					}
				}
			}
			//////////////////////////////////////////////////
			if(me->query_temp("wei/renwu6_9"))//���
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
								me->set("wei/renwu6",1);//�һط��
								me->add("wei/count",1);
								destruct(WeiNpc);
								Wei_Npc=load_npc("wei_fang");
								((CChar *)Wei_Npc)->set("ok",1);
								((CChar *)Wei_Npc)->set("title",  "����������" );
								((CChar *)Wei_Npc)->move(env);
								
								tell_object(me, "\n$YELС�����ĴӺ���һ�ѱ�ס��褣��������Ц��������������ɻ����ˣ�����һ���ȣ���");   
								tell_object(me, "$YEL��褺�������ŭ�����������������߿�������");   
																
								tell_object(me, "\n$YEL���С���һ��˷�褣���������������3000�㾭�顣");   
								me->add("combat_exp",3000);
								me->UpdateMe();
							}
							else
							{
								tell_object(me, "\n$YEL����������ȵؿ�����ѩ��������塣");   
								tell_object(me, "$YEL�������ѩ��������ִ��");   
								tell_object(me, "$YEL��ѩ�����嶪���ڵأ��������ܿ��ˡ�");   
								tell_object(me, "$YEL���ʰ�����壬ϸϸ�ز��øɾ����þ�������������Ȼ��ת���뿪�ˡ�\n");   
								
								tell_object(me, "\n$YEL��Ū�ɳ�׾���������Σ���������������2800�㾭�顣");   
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
			if(me->query_temp("wei/renwu7_10"))//��ѩ
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
								me->set("wei/renwu7",1);//�һ���ѩ
								me->add("wei/count",1);
								destruct(WeiNpc);
								Wei_Npc=load_npc("wei_zengrou");
								((CChar *)Wei_Npc)->set("ok",1);
								((CChar *)Wei_Npc)->set("title",  "����������" );
								((CChar *)Wei_Npc)->move(env);
								
								tell_object(me, "\n$YEL��ѩ����һת����һ�������Ӷ���С����ǰ�����ϣ�ֻ�����ӹ�µµ�ɿ��ת��������");   
								tell_object(me, "$YEL��ѩ����ض�С��˵�������²��Ǽ��㣿��");   
								tell_object(me, "$YELС�����ƴ�Ц��������Ȥ��Ȥ�������ж��ֿ����������ˣ���");   
								
								tell_object(me, "\n$YEL���С���һ�����ѩ����������������2800�㾭�顣");   
								me->add("combat_exp",2800);
								me->UpdateMe();
							}
							else
							{
								tell_object(me, "\n$YEL����������ȵؿ�����ѩ��������塣");   
								tell_object(me, "$YEL�������ѩ��������ִ��");   
								tell_object(me, "$YEL��ѩ�����嶪���ڵأ��������ܿ��ˡ�");   
								tell_object(me, "$YEL���ʰ�����壬ϸϸ�ز��øɾ����þ�������������Ȼ��ת���뿪�ˡ�\n");   
								
								tell_object(me, "\n$YEL��Ū�ɳ�׾���������Σ���������������3000�㾭�顣");   
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
			if(me->query_temp("wei/renwu9_4"))//˪��
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
								tell_object(me, "\n$YEL˪�����˹�����");   
								tell_object(me, "$YEL˪��Խ��Խ���ģ������̲�סſ��С���ļ���Ϸ������������");  
								tell_object(me, "\n$HIR��õ���10��ʵս����Ľ�����");  
								me->add("combat_exp",10);
								me->UpdateMe();
								if(me->query("wei/count")!=6 )
								{
									tell_object(me, "\n$YEL˪������С������������ϸϸ�ؿ��˿���");   
									tell_object(me, "$YEL˪�������֡�ž����һ���ƴ���С�����ϣ�");   
									tell_object(me, "$YEL˪�������������ˡ�");  
									destruct(WeiNpc);
								}
								else
								{
									me->set("wei/renwu9",1);//�һ�˪��
									me->add("wei/count",1);
									destruct(WeiNpc);
									/*
									Wei_Npc=load_npc("wei_shuanger");
									((CChar *)Wei_Npc)->set("ok",1);
									((CChar *)Wei_Npc)->set("title",  "����������" );
									((CChar *)Wei_Npc)->move(env);
									*/
									tell_object(me, "\n$YELС������˪�����������������������һ���ǣ����󹦸�ɣ��׸��������");   
									
									tell_object(me, "\n$YELС������˫����ͬʱҲ�������������������һ������Ȼ����ʮ��������Ʊ��");   
									CContainer * bot = load_item("yinpiao1");
									bot->set("value",100000);
									bot->move(me);
									
									char msg[255];
									g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s����%s(%s)$HIY���߽�����������֮����չ�������᳦��������С���һ���λ�绨�������ӡ�$COM",  me->querystr("family/family_name"),me->name(1),me->id(1)));

									tell_object(me, "\n$YEL�η�������һȺ������̵��ϴ��ｫ˪������ŮΧ�������������ǻ����������������");   
									
									g_Channel.do_channel(&g_Channel, 0, "news", "\n\n                         $HIWС���Ļ���ʼ�ˣ�\n               ��Ķ������˵����𣬼�������Ŵ�����ϲ���뻶�ֵ����֡�\n          һ��Ⱥ�˴�ӵ�����κ�����С�����߸�ǧ�����ĵ��������ϴ������С�\n\n");
									g_Channel.do_channel(&g_Channel, 0, "news", "$HIW\n\n                    ֻ�������˿տն��ߺ�һ����һ����أ�\n                ��С�����ȶ��Ŵ��Ź��˹��£���˸���ͷ��\n          ��λ����ŤŤ����ػ���������һ���ӣ�����һ��ӯӯ������ȥ��\n\n");
									g_Channel.do_channel(&g_Channel, 0, "news", "$HIW\n\n                    �����˿տն��ߺ�һ�������ݸ��ã�\n                С�������߸�����һ�����źη���������ȥ��\n                ֱ�ֵúη���ֱ�С����У���ϱ������\n\n");
									g_Channel.do_channel(&g_Channel, 0, "news", "$HIW\n\n                    �����˿տն��ߺ�һ�������޶԰ݣ�\n                 �߸����ﶼֻ�����ź�С����һǷ��ʾ�⡣\n             С��ȴ�ֹ���һ�����£�������λ����һһ�а���\n\n");
									g_Channel.do_channel(&g_Channel, 0, "news", "$HIW\n\n                    ������ſտն��ߺ������붴����\n       ϲ���̵�С��ǣ���˺���һͷ�������߸��ߴ�������һͬ���������ã�\n\n");

									//������
									MAP2USER * user;
									iterator_user p;
									CUser * obj;
									user = users();
									for ( p=user->begin(); p!=user->end(); p++)
									{
										obj = p->second;
										char msg[255];
										CContainer * gift;
										
										snprintf(msg, 255, "����Ʈ��������һ�����ӣ���ƫ����������Ļ��С���\n���һ����������һ��ϲ����һƿ�ƺ�һ�鵰�⡣");
										tell_object(obj,msg);
										
										gift=load_item("cake");
										gift->move(obj);
										
										if (EQUALSTR(obj->querystr("gender"), "����"))	//��Ҷ��
										{
											gift=load_item("jiuping2");
											gift->move(obj);
										}
										
										if (EQUALSTR(obj->querystr("gender"), "Ů��"))	//Ů����
										{
											gift=load_item("nverhong");
											gift->move(obj);
										}
										
										if (EQUALSTR(obj->querystr("gender"), "����"))	//׳����
										{
											gift=load_item("jiuping");
											gift->move(obj);
										}
										
										gift=load_item("baozi");
										gift->set_name("С������λ���޵�ϲ��", "xi tie");
										gift->set("value",0l);
										gift->set("long","����һ��С������λ���޵�ϲ����");
										gift->set("unit","��");
										gift->move(obj);

										CContainer * env = load_room("pk");
										if(env->query("happy"))		//����
										{
											if(obj->query("level")>30 && obj->query("combat_exp")>81000 &&
												obj->query_skill("force", 1) > 60 && obj->query_skill("dodge", 1) >60 
												&& obj->query_skill("parry", 1) >60 && obj->query_skill("literate", 1) >60)
											{
												gift=load_item("dazongzi");
												if(random(100)>80 )
													gift->set("����",1);
												gift->move(obj);
												snprintf(msg, 255, "������ķ���������л���һ��������������ӡ�");
												tell_object(obj,msg);
											}
										}
									}
									
									tell_object(me, "\n$YEL�η���������һ���������ߵ����ǰ��");   
									tell_object(me, snprintf(msg, 255, "$YEL�η���˵���������Ǳ����н����ܳ��ף�ȫ����%s����������С��˼���������°ɣ���",query_respect(me)));   
									tell_object(me, "\n$YEL�η���������һ����������");   
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
											tell_object(me, snprintf(msg, 255,"\n$YEL�η�������һ�룬��˵�������ϴ�һ������Ŷ���һ�������������Ҳ��֪������ʲô������Ҳһ���͸�%s�ɣ�Ҳ��%s�õ����أ���",query_respect(me),query_respect(me))); 
											tell_object(me, "\n$YEL�η����ݸ�����һ������ʫ�����ס���"); 
											break;
										case 1:
											bot=load_item("cunyang_sword");
											tell_object(me, snprintf(msg, 255,"\n$YEL�η�������һ�룬��˵�������ϴ�һ������ʿ������һ���ƽ���˵ʲô����������а����һ���������ֲ����Ŵ��ɱɱ��Ҫ��Ҳûʲô�ã�����Ҳһ���͸�%s�ɣ�Ҳ��%s�õ����أ���",query_respect(me),query_respect(me))); 
											tell_object(me, "\n$YEL�η����ݸ�����һ�ѡ�����������"); 
											break;
										case 2:
											bot=load_item("zihulu");
											tell_object(me, snprintf(msg, 255,"\n$YEL�η�������һ�룬��˵�������ϴ�һ�����������ؤ����һ���ƺ�«���������װ��Щ�ƣ���֪�����ܲ��ܺ��ˣ����%s�������Ļ������Ҿ��ø�%s�����ðɣ���",query_respect(me),query_respect(me))); 
											tell_object(me, "\n$YEL�η����ݸ�����һ����С�Ϻ�«����"); 
											break;
										case 3:
											bot=load_item("dazongzi");
											tell_object(me, snprintf(msg, 255,"\n$YEL�η�������һ�룬��˵������ǰ�������������һЩ���ӣ������м���ʣ��û����ģ���֪������û�����%s������Ļ�����%s����һ���ɣ���",query_respect(me),query_respect(me))); 
											tell_object(me, "\n$YEL�η����ݸ�����һ�������ӡ���"); 
											break;
										case 4:
											bot=load_item("huanchunwan");
											tell_object(me, snprintf(msg, 255,"\n$YEL�η�������һ�룬��˵�����������ﻹ�м������Ƶ�ҩ�裬������ú�%sͶԵ������%sһ�Űɣ���",query_respect(me),query_respect(me))); 
											tell_object(me, "\n$YEL�η����ݸ�����һ�š������衹��"); 
											break;
										}
										bot->set("ok",1);
										bot->move(me);
									}

									if(me->query("disfigurement"))//�޸�֮ǰʹ�õ�����ɵĻ��ݼ�¼
									{
										tell_object(me, snprintf(msg, 255,"\n$YEL�η�����ϸ���������˺����۵���ף���Ӵ����λ%s����ô�����������ôҲ������ѽ������",query_respect(me)));  
										tell_object(me, "$YEL�η����ӿڴ����ó�һ�и�ҩ��������˵���͸���Ĩ����ȥ");  
										tell_object(me, "$YEL��ֻ�����������쬵ģ�����һ�������ɵĴ��һ����ԭ���η��������õľ���һ�С������̺��项��\n");  
										tell_object(me, "$HIR�����ò�ָ��ˡ�\n");  
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

		snprintf(msg, 255, "����Ʈ��������һ�����ӣ���ƫ����������Ļ��С���\n���һ����������һ��ϲ����һƿ�ƺ�һ�鵰�⡣");
        tell_object(obj,msg);

		gift=load_item("cake");
		gift->move(obj);

		if (EQUALSTR(obj->querystr("gender"), "����"))	//��Ҷ��
		{
			gift=load_item("jiuping2");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "Ů��"))	//Ů����
		{
			gift=load_item("nverhong");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "����"))	//׳����
		{
			gift=load_item("jiuping");
			gift->move(obj);
		}

		gift=load_item("anmenkey");
		gift->set_name("С������λ���޵�ϲ��", "xi tie");
		gift->set("value",0l);
		gift->set("long","����һ��С������λ���޵�ϲ����");
		gift->set("unit","��");
		gift->move(obj);
    }
    
	return 1;
}

ROOM_END;
