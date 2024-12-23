//lj_tielao.h
//��ɽ����
//2002-06-07

NPC_BEGIN(CNlj_tielao);

virtual void create()
{
	set_name("��ɽ����", "tie lao");
    set("gender", "Ů��");
	set("icon", girl1);

    set("age", 8);
    set("attitude", "friendly");
//	set("long","��Ů�޶��ƺ��Ǹ�Ѿ�ߣ�����ü��Ŀ�㡣");
    set("combat_exp", 1);
	set("hp",500);
	set("max_hp",800);
	set("eff_hp",800);
	set_weight(50000000);

	set("max_mp",800);
	set("mp",800);

	set("temp/str",random(7)+18);
	set("temp/count",84-query("temp/str"));
	set("temp/dex",random(7)+18);
	set("temp/count",query("temp/count")-query("temp/dex"));
	set("temp/int",random(7)+18);
	set("temp/count",query("temp/count")-query("temp/int"));
	set("temp/con",query("temp/count"));

	add("str",query("temp/str"));
	add("dex",query("temp/dex"));
	add("con",query("temp/con"));
	add("int",query("temp/int"));
	del("temp");

	set("level",8);
	set("per",20+query("int")-query("str"));
	set("no_kill",1);
	set("lost",6);
	
	set("chat_chance", 30);
	set("chat_chance_combat", 8+int(query("int")/10)+int(query("level")/20));

//	reset();
	call_out(do_reset, 15);
	set("no_talk",1);
	set("no_huan",1);
	set("no_kill",1);

}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("owner"))
	{
		char msg[255];
		CUser * player;
		snprintf(msg,255,"%d",npc->query("owner"));
		player=find_online(msg);
		if(!player)
		{
			CContainer * env = load_room("���ն�����");
			if(env->query(msg))
				env->del(msg);
			destruct(npc);
		}
		else
		{
			npc->set_leader(player);
			int skill_level;
			npc->set("str",player->query("lj/tielao/str"));
			npc->set("dex",player->query("lj/tielao/dex"));
			npc->set("int",player->query("lj/tielao/int"));
			npc->set("con",player->query("lj/tielao/con"));
			npc->set("per",player->query("lj/tielao/per"));
			npc->set("age",player->query("lj/tielao/age"));
			npc->set("level",player->query("lj/tielao/level"));
			npc->set("combat_exp",player->query("lj/tielao/combat_exp"));
			npc->set("study/fight_exp",player->query("lj/tielao/fight_exp"));
			npc->set("study/level_exp",player->query("lj/tielao/level_exp"));

			npc->set("max_hp",npc->query("level")*(80+npc->query("con")));
			npc->set("hp",npc->query("max_hp"));
			npc->set("eff_hp",npc->query("max_hp"));
			npc->set("max_mp",npc->query("level")*100);
			npc->set("mp",npc->query("max_mp"));
			npc->set("mp_factor", 2*npc->query("level"));
			npc->set_weight(10000);

			if(npc->query("level")>=15)
			{
				skill_level=(1+int(npc->query("int")/10))*(npc->query("level")-14)+1;
				npc->set_skill("force", skill_level);
				npc->set_skill("unarmed", skill_level);
				npc->set_skill("dodge", skill_level);
				npc->set_skill("parry", skill_level);
				npc->set_skill("finger",skill_level);
				npc->set_skill("hand",skill_level);
				npc->set_skill("strike", skill_level);
				npc->set_skill("sword",skill_level);
			}
			if(npc->query("level")>=20)
			{
				skill_level=(1+int(npc->query("int")/10))*(npc->query("level")-19)+1;
				npc->set_skill("zhemei_shou",skill_level);
				npc->set_skill("liuyang_zhang",skill_level);
				npc->set_skill("tianyu_qijian",skill_level);
				npc->set_skill("yueying_wubu",skill_level);
				npc->set_skill("bahuang_gong", skill_level);
				npc->set_skill("rouqing_zhi",skill_level);
			}
			if(npc->query("level")>=25)
			{
				npc->map_skill("force", "bahuang_gong");
				npc->map_skill("strike","liuyang_zhang");
				npc->map_skill("dodge", "yueying_wubu");
				npc->map_skill("unarmed", "liuyang_zhang");
				npc->map_skill("strike","liuyang_zhang");
				npc->map_skill("hand", "zhemei_shou");
				npc->map_skill("parry", "liuyang_zhang");
				npc->map_skill("sword","tianyu_qijian");
				npc->map_skill("finger","rouqing_zhi");
			}
			if(npc->query("level")>=28)
			{
				if(random(2))
				{
					npc->prepare_skill("strike","liuyang_zhang");
					npc->prepare_skill("hand","zhemei_shou");
				}
				else
					npc->prepare_skill("finger","rouqing_zhi");
			}
			npc->FlushMyInfo();
		}
	}
}

virtual char * chat_msg_combat()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * player;
		CFightRoom * obj;
		snprintf(msg,255,"%d",query("owner"));
		player=find_online(msg);
		if(!player)
		{
			CContainer * env = load_room("���ն�����");
			if(env->query(msg))
				env->del(msg);
			destruct(this);
		}
		else
		{
			if(!player->query_temp("fight/is_fighting"))
			{
				obj=(CFightRoom *)environment();
				obj->End_Fight();
			}
			else if(player->query_temp("fight/fight_team")!=query_temp("fight/fight_team"))
			{
				if(DIFFERSTR(player->querystr("gender"), "Ů��"))
					tell_object(player, "$YEL��ɽ���ѣ������û���ĵģ���Ҫ���ٴ����Ҿ������㿴����\n");
				else
					tell_object(player, "$YEL��ɽ���ѣ����ǲ��Ǽ������ഺ��פ�����Բ����۸��ң��ߣ����ٸҴ��ҵĻ����ҾͲ���Ҫ�����ң���\n");
				obj=(CFightRoom *)environment();
				obj->End_Fight();
			}
			else if(!player->query_temp("lj/tielao"))
			{
				player->set_temp("lj/tielao",1);
			}
			else if(query("level")<30 && random(3))
			{
				//���������Ҷ�ս�Ļ������þ���
				CContainer * env = environment();
				DTItemList * list = env->Get_ItemList();  
				POSITION p = list->GetHeadPosition(); 
				while(p) 
				{ 
					CContainer * obj1 = list->GetNext(p);
					if(! obj1->is_character()) continue; 
					CChar * target = (CChar *)obj1;  
					if(!userp(target))	continue;
					if(target->query_temp("fight/fight_team")!=query_temp("fight/fight_team"))
					{
						set("noexp",1);
						break;
					}
				}
				//
				if(DIFFERSTR(((environment())->environment())->querystr("area"), "house")&&!query("noexp")) 
				{
					add("study/fight_exp",int(query("int")/10));
					tell_room(environment(), snprintf(msg, 255,"\n$HIR%s��ʵս���������ˡ�",name(1)));
				}
				if(query("noexp"))del("noexp");
			}
			else if(query("level")>=30 && random(3))
			{
				if(query("level")>=90 )
				{
					if(random(2))
					{
						CContainer * jian = PresentName(querystr("wuqi"), IS_ITEM);
						switch(random(9))
						{
						case 0:
							perform_action("strike zhong", 1);
							break;
						case 1:
							perform_action("hand duo", 1);
							break;
						case 2:
							perform_action("sword san", 1);
							break;
						case 3:
							perform_action("force powerup", 0);
							break;
						case 4:
							if(query_weapon() == jian && jian)
								command(snprintf(msg, 40, "unwield %ld", jian->object_id()));
							break;
						case 5:
							if(jian && ! query_weapon())
								command(snprintf(msg, 40, "wield %ld", jian->object_id()));
							break;
						case 6:
							perform_action("force recover", 0);
							break;
						case 7:
							perform_action("sword kuangwu", 1);
							break;
						case 8:
							perform_action("finger caiyue", 0);
							break;
						}
					}
				}
				if(query("level")>=70 )
				{
					if(random(2))
					{
						CContainer * jian = PresentName(querystr("wuqi"), IS_ITEM);
						if(query("hp")<int(query("max_hp")*0.3))
							perform_action("force recover", 0);
						else
						{
							switch(random(8))
							{
							case 0:
								perform_action("strike zhong", 1);
								break;
							case 1:
								perform_action("hand duo", 1);
								break;
							case 2:
								perform_action("sword san", 1);
								break;
							case 3:
								perform_action("force powerup", 0);
								break;
							case 4:
								if(query_weapon() == jian && jian)
									command(snprintf(msg, 40, "unwield %ld", jian->object_id()));
								break;
							case 5:
								if(jian && ! query_weapon())
									command(snprintf(msg, 40, "wield %ld", jian->object_id()));
								break;
							case 6:
								perform_action("force recover", 0);
								break;
							case 7:
								perform_action("finger caiyue", 0);
								break;
							}
						}
					}
				}
				else if(query("level")>=60 )
				{
					if(random(2))
					{
						if(query("hp")<int(query("max_hp")*0.4))
							perform_action("force recover", 0);
						else
						{
							switch(random(5))
							{
							case 0:
								perform_action("strike zhong", 1);
								break;
							case 1:
								perform_action("hand duo", 1);
								break;
							case 2:
								perform_action("force recover", 0);
								break;
							case 3:
								perform_action("force powerup", 0);
								break;
							case 4:
								perform_action("finger caiyue", 0);
								break;
							}
						}
					}
				}
				else if(query("level")>=50 )
				{
					if(random(2))
					{
						if(query("hp")<int(query("max_hp")*0.5))
							perform_action("force recover", 0);
						else
						{
							switch(random(2))
							{
							case 0:
								perform_action("force recover", 0);
								break;
							case 1:
								perform_action("force powerup", 0);
								break;
							}
						}
					}
				}
				else if(query("level")>=40 )
				{
					if(random(2))
						perform_action("force recover", 0);
				}
				//���������Ҷ�ս�Ļ������þ���
				CContainer * env = environment();
				DTItemList * list = env->Get_ItemList();  
				POSITION p = list->GetHeadPosition(); 
				while(p) 
				{ 
					CContainer * obj1 = list->GetNext(p);
					if(! obj1->is_character()) continue; 
					CChar * target = (CChar *)obj1;  
					if(!userp(target))	continue;
					if(target->query_temp("fight/fight_team")!=query_temp("fight/fight_team"))
					{
						set("noexp",1);
						break;
					}
				}
				//
				if(DIFFERSTR(((environment())->environment())->querystr("area"), "house")&&!query("noexp")) 
				{
					int fight_exp=random(5)+1;
					add("study/fight_exp",fight_exp);
					if(query("study/fight_exp")<=query("study/level_exp"))
						tell_room(environment(), snprintf(msg, 255,"\n$HIR%s��ʵս���������ˣ����������黹��%d�㡣\n(exp + %d)",name(1),query("study/level_exp")-query("study/fight_exp"),fight_exp));
					else
						tell_room(environment(), snprintf(msg, 255,"\n$HIR%s��ʵս�����Ѿ��������������飬�޷��ټ�����ս����������ߵľ����ˡ�",name(1)));
				}
				if(query("noexp"))	del("noexp");
			}
		}
	}
	return 0;
}

virtual char * chat_msg()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * player;
		snprintf(msg,255,"%d",query("owner"));
		player=find_online(msg);
		if(!player)
		{
			CContainer * env = load_room("���ն�����");
			if(env->query(msg))
				env->del(msg);
			destruct(this);
		}
		else
		{
			int exp_reward;
			if(query("combat_exp")>100)
				player->set("lj/tielao/fight_exp",query("study/fight_exp"));
			if(EQUALSTR(environment()->name(1),"�ʹ�����") && query("level")>=75)
			{
				if(player->query("lj/renwu9"))
				{
					CNpc * zhuxu = load_npc("lingjiu_xuzhu");
					zhuxu->move(player->environment());
					tell_object(player, "\n$HIR���������������һ��Ҿ������˵���������͸����ˣ����չ������Ѱ����׵���");
					tell_object(player, "$HIR����������Ҿ�һͬ��ʼ����ʦ�������跨��������ʦ���ĳ�ޡ���\n");
					if(EQUALSTR(player->querystr("gender"), "Ů��"))
						tell_object(player, "$HIR��ɽ����Ҳ��Ц����˵������������ڻ������ɵ���������ң�����Ӧ�þͿ��Բ�Ҫ���鷳���ˡ���");
					else
						tell_object(player, "$HIR��ɽ����Ҳ��Ц����˵������С�ӣ����ڻ������ɵ���������ң�����Ӧ�þͿ��Բ�Ҫ���鷳���ˡ���");
					tell_object(player, "$HIR����Ҫ���ܶ�������һ�٣������������չ��У����ѱ���һ���������㡣��\n");
					tell_object(player, "$HIR���ţ������������������һ��Ҿ��˵������ʱ�䲻���ˣ����Ǹ���ˡ���\n");
					player->set("lj1/renwu_ok",player->query("lj/tielao/count")+1);
					player->set("lj1/renwu_level",query("level"));
					player->set("lj1/����",player->query("lj/renwu89"));					
					player->del("lj");
					player->set("lj/renwu_ok",player->query("lj1/renwu_ok"));
					player->set("lj/renwu_level",player->query("lj1/renwu_level"));
					player->set("lj/����",player->query("lj1/����"));
					player->del("lj1");
					player->delete_temp("lj");
					destruct(zhuxu);
					destruct(this);
					tell_object(player, "$HIR�㿴�����Ѻ���������Խ���ʳǵı�Ӱ�������ڲ�����Щ����ʧ�䡣");
					tell_object(player, "$HIRͬ����ʮ�գ������������빲�������Ѻ���֮�����˸��顣");
					tell_object(player, "$HIR�����Ƿ��ŵı�Ӱ��������ǰ�ĳ��轣�裬�ػ�ʯ���ϵ�����Ѫ�ᣬ");
					tell_object(player, "$HIR����ʫ��������緢��������ͷ�ķ��β�������ֵļ��䶼һһӡ����ǰ��");
					tell_object(player, "$HIR��ֻ������������ǻ����˵ļ�ǿ��������˵�ʹ�࣬һ����Ϊ��������");
					tell_object(player, "$HIR��������һ��������ȴ������һ�ּ��˵ĸо���\n");
					tell_object(player, "$HIR�ҡ������������Ѫ������������˵���Ѿ���������һ��ңԶ���Ե����ˡ�");
					tell_object(player, "$HIR��ʮ�����������Ѽ����ĳɳ����γ����ǵ��길ĸ�����Լ��������Ӱ��ͻȻ������һ�ֶ�˫�׵����Ρ���\n");
					tell_object(player, "$HIR�Ұ�����");
					tell_object(player, "$HIR������ؼ���--���������ν����");
					tell_object(player, "$HIR���ǣ����ӵļ�ȴ�ںδ�����\n");
					tell_object(player, "$HIR��ҹ����");
					tell_object(player, "$HIR���ݵĽ�ͷ����");
					tell_object(player, "$HIR��һ����������ˡ���\n");
					player->del("lj/renwu9");
					g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s����%s(%s)$HIY����ǧ����࣬���ڻ�����ɽ���ѵ�������������$COM",  player->querystr("family/family_name"),player->name(1),player->id(1)));
				}
			}
			else
			{
				if(query("hp")<=int(query("max_hp")*0.8) && !player->query("lj/renwu88")&& player->query("lj/renwu89")>=7&&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu88",1);
					player->del("lj/renwu89");
					tell_object(player, "\n$YEL���Ѱ���е���ߣ�˵�������޶������Ѵ��������������Ƶ����о��裬���֪��Ϊ�β��㲥���һ�С������к����һ�У�");
					tell_object(player, "$YEL������Ϊ�������Ƶ�����ʽ�������۽𡹡�����ʽ����б��·��ϼ�������������ġ��������������������");
					tell_object(player, "$YEL��������������ʼ�ͳ��䲻��򵹶��ֵ�������");
					
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						tell_object(player, "$YEL������֪���ˣ����������ҿ�������\n");
						player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
						player->add("pro/skill/liuyang_zhang",1);
						player->add("lj/pro/skill/liuyang_zhang",1);
						player->FlushMySkill(player);
						tell_object(player, "\n\n$HIR�������ָ������������ǰ������һ�������Ʒ�������ѧ�������˸���һ��ε�����\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR�����������ѽ��⡰��ɽ�����ơ��ľ������ڣ�����ѧ�������˸���һ��ε����,����������1000��ľ��顣\n\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"����") && !player->query("lj/renwu81")&&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu81",1);
					player->add("lj/renwu89",1);
					add("per",1);

					tell_object(player, "\n$YEL���ѿ��ų����ľ�ɫ��ң�������ϵ�������Ƶ���������˵������������ǻ���ȥ�����һ�ΰɣ�");
					tell_object(player, "$YEL���֪��ɽ�������С������ƶ��������оͳ�����ά��Ħڵ�ġ�������¡���\n");
					tell_object(player, "$YEL                  ��֪����£�");
					tell_object(player, "$YEL                  �������Ʒ塣");
					tell_object(player, "$YEL                  ��ĺ��̶����");
					tell_object(player, "$HIR                  �����ƶ���$YEL����");
					
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
						player->add("pro/skill/liuyang_zhang",1);
						player->add("lj/pro/skill/liuyang_zhang",1);
						player->FlushMySkill(player);
						tell_object(player, "\n\n$HIR�����������ѽ��⡰��ɽ�����Ƶڶ�ʽ�������ƶ��������ĵ�ʣ�����ѧ�������˸���һ��ε�����\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR�����������ѽ��⡰��ɽ�����Ƶڶ�ʽ���ĵ�ʣ�����ѧ�������˸���һ��ε����,����������1000��ľ��顣\n\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"������") && !player->query("lj/renwu82")&&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu82",1);
					player->set_temp("lj/renwu82",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL���Ѻ�������μ�ǵĽ�ͷ��ͻȻ����˵������ǰ����Ǽ������ˡ�");
					tell_object(player, "$YEL��ɫ�ƺ�ʮ����Ȼ��Ҳ���������˵������˵����¡�");
					tell_object(player, "$YELֻ����˫����ͻ�ž�â������һ֦���������ֽ�������������·�˷׷׽кá�");
					if(player->query_skill("music",1))
						tell_object(player, "$YEL���ƺ�Ҳ��������Ⱦ�����ϵ���������������������ɪ���֮����·���ֶ�밵�Դ��ᣬ��Ŀ������");
					
					(player->environment())->set("no_fight",1);
					player->disable_player("������");
					
					set("chat_chance", 0l);
					call_out(do_wujian, 1);	
				}
				if(EQUALSTR(environment()->name(1),"�����ַ�") && !player->query("lj/renwu83") &&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu83",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL���ѿ��ų����ָ�ʫ�������˴ڶ����ſ��ȼ硢��ʿ����������̾��������ǧ�������������־������û����û��");
					tell_object(player, "$YEL������ǰ����᯲��ڴ�д�¡��ͼ������糯��һʫ��ʫ��--\n");
					tell_object(player, "$YEL                  ������İ��⺮��ݺ�����ݴ�ɫ����");
					tell_object(player, "$YEL                  �������ӿ��򻧣��������ӵǧ�١�");
					tell_object(player, "$YEL                  ��ӭ�����ǳ��䣬�������¶δǬ��");
					tell_object(player, "$YEL                  ���з�˳��Ͽͣ�$HIR����һ���ͽ���$YEL��\n");
					tell_object(player, "$YEL��ʮ��ǰ�����ڴ�ң˼���ˣ��������������е�һ�С�����һ���ͽ��ѡ���");
					tell_object(player, "$YEL�������ȴ�����δ˹ʵ�,���������˷�֮̾������");	  
					
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
						player->add("pro/skill/liuyang_zhang",1);
						player->add("lj/pro/skill/liuyang_zhang",1);
						player->FlushMySkill(player);
						tell_object(player, "\n\n$HIR�����������ѽ��⡰��ɽ�����Ƶ���ʽ������һ���ͽ��ѡ���������������ѧ�������˸���һ��ε�����\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR�����������ѽ��⡰��ɽ�����Ƶ���ʽ������һ���ͽ��ѡ���������������ѧ�������˸���һ��ε���⡣");
						tell_object(player, "$HIR����������1000��ľ��顣\n\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"��������") && !player->query("lj/renwu84") &&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu84",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YELһ�������ǣ����Ѻ�Ȼ˵����");
					tell_object(player, "$YEL�������游�����Լ��������ˣ����ʱ��ʫ����������֮�ʳ��ͣ�������ὡ����ڡ���ζ��Ϊ�������ѣ����š������նš���");
					tell_object(player, "$YEL�䳢����Ի���������µ������������ù٣���ʵ�������֮���档����Ƶ����ǳֲŰ������һ����");
					tell_object(player, "$YEL����������ʫ���Ǽ�ϲ����--\n");
					tell_object(player, "$YEL                  ���л����ˣ�ƫ������¡�");
					tell_object(player, "$HIR                  ��ϼ������$YEL��÷���ɽ�����");
					tell_object(player, "$YEL                  �����߻������ת��Ƽ��");
					tell_object(player, "$YEL                  ���Ÿ�ŵ�����˼��մ��\n");
					tell_object(player, "$YELʫ��--���ͽ���½ة�紺��������");
					tell_object(player, "$YEL���ҿ��������С���ϼ�����������");
					
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
						player->add("pro/skill/liuyang_zhang",1);
						player->add("lj/pro/skill/liuyang_zhang",1);
						player->FlushMySkill(player);
						tell_object(player, "\n\n$HIR�㿴������������ʾ����ɽ�����Ƶ���ʽ����ϼ�������������ѧ�������˸���һ��ε�����\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR�㿴������������ʾ����ɽ�����Ƶ���ʽ����ϼ�������������ѧ�������˸���һ��ε�������,������1000��ľ��顣\n\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"����ɽ���") && !player->query("lj/renwu85") &&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu85",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL��������߽��˸���ϵĶػ�Ī�߿ߣ���ǧ���ڣ����������ڽ��˵Ĺ��գ�������ȴ��һ���������ʿ�ǰפ�㣬");
					tell_object(player, "$YELֻ��������������\n");
					tell_object(player, "$YEL                  ��ǰ����ǧ��Ը��");
					tell_object(player, "$YEL                  Ҫ���Ҵ���ɽ�á�");
					tell_object(player, "$YEL                  ˮ���ϳӴ�����");
					tell_object(player, "$YEL                  ֱ���ƺӳ��׿ݡ�");
					tell_object(player, "$HIR                  ���ղγ���$YEL��");
					tell_object(player, "$YEL                  ���������棬");
					tell_object(player, "$YEL                  �ݼ�δ���ݣ�");
					tell_object(player, "$YEL                  �Ҵ���������ͷ��\n");
					tell_object(player, "$YELһ����ϣ�ֻ����˫�־�����ץ��ʯ�ڣ����л�����߶������а�����������֪�����������֪����");
					tell_object(player, "$YEL�����˫�粻ס����������������ʲô�����£���ǰ��������ȴ����һ��˦����");
					if(DIFFERSTR(player->querystr("gender"), "Ů��"))
					{
						tell_object(player, "$YELȴ�����ѻ������˸����⣬ֻ����˵������������Щ�����ˣ�ûһ���Ǻö�������" );
						player->set_temp("apply/per",-1);
						tell_object(player, "\n$HIR�����ű��ȵ��ǰ���������εĵ���ͷ������ȥ������Χ��������Ⱥ��\n��������ʱ-1��\n");
					}
					else
					{
						tell_object(player, "$YELֻ����˵���������Ӱ����мǣ���Ҫ�������˰����ر��ǲ�Ҫ����ϲ��������ˣ���" );
						player->set_temp("apply/int",1);
						tell_object(player, "\n$HIR�㿴�ű�ʹ�е���ɽ���ѣ��������Լ�����о������̲�סҲ��Ŀ������\n���ǻ���ʱ+1��\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"��ٹȲݵ�") && player->query("hp")<player->query("max_hp")/2
					&& player->query("mp")<player->query("max_mp")/2
					&& !player->query("lj/renwu86") &&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu86",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL���ѿ��ź���һ�𱼲����۶��׷ɱ���㣬Ŀ�����ƺ�����Ǹ�⣬����������");
					tell_object(player, "$YEL�����ƴ���ʮ����֮һ��Ǯ����ʫ���ȿ���ի����ڡ�--\n");
					tell_object(player, "$YEL                  Ȫ�ִ�é�ģ�$HIR��ϼ��޵�$YEL��");
					tell_object(player, "$YEL                  ���������ɽ��Ϧ��ʱ��");
					tell_object(player, "$YEL                  �����ܳ��磬�ﻨ����١�");
					tell_object(player, "$YEL                  ����ɨ�޾�����������ڡ�\n");
					tell_object(player, "$YEL��Ҫ�ú���ᡰ��ϼ��޵ᡡ���仰���⾳�����ѽ��������Լ����书����ˡ���ϼ��޵ᡡ�'��");
					tell_object(player, "$YELϣ������������$HIR��$YEL�����Ʒ��ϵ����ã�Ҳ�������ѵ㻯��һ������");
					
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						if(!random(20) && player->query_skill("strike",1)<400)
						{
							player->set_skill("strike",player->query_skill("strike",1)+1);
							player->add("pro/skill/strike",1);
							player->add("lj/pro/skill/strike",1);
							player->FlushMySkill(player);
						}
						else
						{
							player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
							player->add("pro/skill/liuyang_zhang",1);
							player->add("lj/pro/skill/liuyang_zhang",1);
							player->FlushMySkill(player);
						}
						tell_object(player, "\n\n$HIR���ܵ����ѵ�����ָ�㡰��ɽ�����Ƶڰ�ʽ����ϼ��޵ᡡ����С������ֵ����⣬����ѧ�������˸���һ��ε�����\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR���ܵ����ѵ�����ָ�㡰��ɽ�����Ƶڰ�ʽ����ϼ��޵ᡡ���������ѧ�������˸���һ��ε����,������1000��ľ��顣\n\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"�����ʳ�") && !player->query("lj/renwu87") &&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu87",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL������ڻʳǽ��£����ų��ڵ����ӣ�������˵��");
					tell_object(player, "$YEL�����ѣ�һ·�����㽲�����ʫ�ʣ���֪����书��ʽ�������ʫ�����ݻ������ģ���֪��û�кͻʵ��йصģ���\n");
					tell_object(player, "$YEL����΢Ц��ͷ���������������������������л���ʵ��йء�ʷ������ʫ���Ϻ�Ȼ����Ԫ����Ϊ����ة��֪����");
					tell_object(player, "$YELά��گ���ǵһ������֮�̽Ϸ��ţ���������ά������Ȼ��㵷����£�ά����������֮���š�����Ȼ�ڣ������������ˡ���");
					tell_object(player, "$YEL���گ������Ի�����佫��ʫ��Ү������Ȼ��Ի������ż������ҵ�����ϼ�������\n");
					tell_object(player, "$YEL��Ȼ��گ��������ʫԻ��\n");
					tell_object(player, "$YEL                  ���������飬��ɽ���®��");
					tell_object(player, "$YEL                  �������������ಡ�����衣");
					tell_object(player, "$YEL                  �׷������ϣ�$HIR���������$YEL��");
					tell_object(player, "$YEL                  ������£�����ҹ���顣\n");
					tell_object(player, "$YEL����֮��ȻԻ������δ�����ˣ������䲻������κη��д�������");
					tell_object(player, "$YEL�����Ź���ɽ�������ˡ��ഫ�����š���ĺ����ɽ����һ�������������˻���");
					tell_object(player, "$YEL�����Ʒ��У�ȴҪע��һ��$HIR������$YEL�֣���������������֮�鶯Ʈ�ݡ���");
										
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
						player->add("pro/skill/liuyang_zhang",1);
						player->add("lj/pro/skill/liuyang_zhang",1);
						player->FlushMySkill(player);
						tell_object(player, "\n\n$HIR���ܵ����ѵ�����ָ�㡰��ɽ�����Ƶھ�ʽ����������������С������ֵ����⣬����ѧ�������˸���һ��ε�����\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR���ܵ����ѵ�����ָ�㡰��ɽ�����Ƶھ�ʽ���������������������ѧ�������˸���һ��ε����,������1000��ľ��顣\n\n");
					}
				}
				if(player->query_temp("fight/is_fighting") && EQUALSTR(((player->environment())->environment())->name(1),(environment())->name(1)))
				{
					int team;
					CFightRoom * obj=(CFightRoom *)player->environment();
					if(player->query_temp("fight/fight_team"))		//����A��
						team = 1;
					else
						team = 0;
					move(obj);
					obj->Join_Team(this, team);
				}
				else if(query("level")<=30)
				{
					if(query("study/fight_exp")>query("level")*3)	
					{
						DTItemList * list = environment()->Get_ItemList();  
						POSITION p = list->GetHeadPosition(); 
						while(p) 
						{ 
							CContainer * obj = list->GetNext(p);
							if(DIFFERSTR(obj->querystr("id"), "corpse")) continue; 
							
							add("study/fight_exp",-query("level")*3);
							add("study/level_exp",-query("level")*3);
							add("study/shiti",1);
							if(query("study/shiti")>=3)
							{
								add("level",1);
								if(query("level")>14)
								{
									switch(query("level"))
									{
									case 15:
										set_skill("force", 1);
										set_skill("unarmed", 1);
										set_skill("dodge", 1);
										set_skill("parry", 1);
										set_skill("finger",1);
										set_skill("hand",1);
										set_skill("strike", 1);
										set_skill("sword",1);
										break;
									case 20:
										set_skill("zhemei_shou",1);
										set_skill("liuyang_zhang",1);
										set_skill("tianyu_qijian",1);
										set_skill("yueying_wubu",1);
										set_skill("bahuang_gong", 1);
										set_skill("rouqing_zhi",1);
										break;
									case 25:
										map_skill("force", "bahuang_gong");
										map_skill("strike","liuyang_zhang");
										map_skill("dodge", "yueying_wubu");
										map_skill("unarmed", "liuyang_zhang");
										map_skill("strike","liuyang_zhang");
										map_skill("hand", "zhemei_shou");
										map_skill("parry", "liuyang_zhang");
										map_skill("sword","tianyu_qijian");
										map_skill("finger","rouqing_zhi");
										break;
									case 28:					
										if(random(2))
										{
											prepare_skill("strike","liuyang_zhang");
											prepare_skill("hand","zhemei_shou");
										}
										else
											prepare_skill("finger","rouqing_zhi");
										break;
									case 30:
										break;
									}
									CMapping * skills =query_skills();
									CVector v;
									skills->keys(v);
									int skill_level=1+int(query("int")/10);
									for(int i=0; i<v.count(); i++)
									{
										(*skills)[v[i]] += skill_level;
									}
								}
								add("age",1);
								set("combat_exp",CChar::Level2Exp(query("level")));
								set("study/level_exp",query("level")*3);
								del("study/shiti");
								del("study/fight_exp");
								add("max_hp",80+query("con"));
								set("hp",query("max_hp"));
								set("eff_hp",query("max_hp"));							
								add("max_mp",100);
								set("mp",query("max_mp"));
								add("mp_factor", 2);
								
								FlushMyInfo();
																
								player->set("lj/tielao/age",query("age"));
								player->set("lj/tielao/str",query("str"));
								player->set("lj/tielao/dex",query("dex"));
								player->set("lj/tielao/int",query("int"));
								player->set("lj/tielao/con",query("con"));
								player->set("lj/tielao/per",query("per"));
								player->set("lj/tielao/combat_exp",query("combat_exp"));
								player->set("lj/tielao/level_exp",query("study/level_exp"));

								tell_room(environment(), snprintf(msg, 255,"\n$HIR%sһ�ſڱ�ҧ��%s�ʺ��ϣ����ڹ�������������˱����Ѫ��",name(1),obj->name(1)));
								tell_room(environment(), snprintf(msg, 255,"$HIR%s�ȱ�����Ѫ�����Ӹ߸߹���һ��ָ�죬һ��ָ�أ�����˻�����Ψ�Ҷ�������",name(1)));
								tell_room(environment(), snprintf(msg, 255,"$HIRֻ��%s����������̣��������Դ���Χ����������������\n",name(1)));
								destruct(obj);

								if(query("level")==30)
									tell_room(environment(), snprintf(msg, 255,"$HIR%s��������һ����������˵���������ڵ��书����ǿ���԰�����һ��æ�ˡ�\n",name(1)));
								
								tell_room(environment(),snprintf(msg, 255,"$HIR%s�ƺ���ò������ϸ΢�ı仯,����ȼ�Ҳ���Ϊ%d����",name(1),query("level")));
								
								if(player->query("lj/tielao/level")<query("level"))
								{
									player->set("lj/tielao/level",query("level"));
									exp_reward=query("level")*(50+random(50));
									player->add("combat_exp",exp_reward);
									player->UpdateMe();
									tell_object(player, snprintf(msg, 255,"\n\n$HIR�㱣�������й��������%d��ľ��齱����\n\n",exp_reward));
								}
								else
								{
									player->set("lj/tielao/level",query("level"));
									tell_object(player, "\n\n$HIR�����ӷǷ����������ڴ��������棬������ֹͣ����Ϊ���������Ը���\n\n");									
								}
							}
							break;
						}
					}
				}
				else if(query("level")<=75)
				{
					if(query("study/fight_exp")>=query("study/level_exp") && query("study/fight_exp"))	
					{
						DTItemList * list = environment()->Get_ItemList();  
						POSITION p = list->GetHeadPosition(); 
						while(p) 
						{ 
							CContainer * obj = list->GetNext(p);
							if(DIFFERSTR(obj->querystr("id"), "corpse")) continue; 
												
							del("study/fight_exp");
							add("level",1);
							set("combat_exp",CChar::Level2Exp(query("level")));
							LONG exp = CChar::Level2Exp(query("level") + 1) - CChar::Level2Exp(query("level"));
							set("study/level_exp",int(exp/25));
							add("age",1);
											
							CMapping * skills =query_skills();
							CVector v;
							skills->keys(v);
							int skill_level=2+int(query("int")/10);
							for(int i=0; i<v.count(); i++)
							{
								(*skills)[v[i]] += skill_level;
							}
							add("max_hp",80+query("con"));
							set("hp",query("max_hp"));
							set("eff_hp",query("max_hp"));	
							add("max_mp",100);
							set("mp",query("max_mp"));
							add("mp_factor", 2);
							
							FlushMyInfo();
							player->set("lj/tielao/age",query("age"));
							player->set("lj/tielao/level",query("level"));
							player->set("lj/tielao/str",query("str"));
							player->set("lj/tielao/dex",query("dex"));
							player->set("lj/tielao/int",query("int"));
							player->set("lj/tielao/con",query("con"));
							player->set("lj/tielao/per",query("per"));
							player->set("lj/tielao/combat_exp",query("combat_exp"));
							player->set("lj/tielao/level_exp",query("study/level_exp"));
							exp_reward=query("level")*(100+random(100));
							player->add("combat_exp",exp_reward);
							player->UpdateMe();

							tell_room(environment(),snprintf(msg, 255,"$HIR%s�����ˣ��ȼ����Ϊ%d����",name(1),query("level")));

							tell_room(environment(), snprintf(msg, 255,"\n$HIR%sһ�ſڱ�ҧ��%s�ʺ��ϣ����ڹ�������������˱����Ѫ��",name(1),obj->name(1)));
							tell_room(environment(), snprintf(msg, 255,"$HIR%s�ȱ�����Ѫ�����Ӹ߸߹���һ��ָ�죬һ��ָ�أ�����˻�����Ψ�Ҷ�������",name(1)));
							tell_room(environment(), snprintf(msg, 255,"$HIRֻ��%s����������̣��������Դ���Χ����������������\n",name(1)));
							destruct(obj);

							tell_object(player, snprintf(msg, 255,"\n\n$HIR�㱣�������й��������%d��ľ��齱����\n\n",exp_reward));
							break;
						}
					}
				}
				else if(query("level")>=75)
				{
					if(!player->query("lj/renwu9") && player->query("lj/renwu8"))
					{
						tell_room(environment(),snprintf(msg, 255,"$HIR%s����˵����������Ȼ���Ǽ��˷��֣������������ڶ࣬����������������Ȼ���Ի�����",name(1)));
						tell_room(environment(),"$HIR���֮��ֻ�ñ������ţ���Σ�յĵط������ȫ�ĵط���");
						tell_room(environment(),"$HIR��ǰ�Ҵ�ɱ��ʱ�����������Ļʹ��ĵ��±����ж������ʱ����ȥ�Ǵ��ܱܰɣ���\n");
						player->set("lj/renwu9",1);
						player->del("lj/renwu8");
					}
					if(query("study/fight_exp")>=query("study/level_exp") && query("study/fight_exp")&& query("level")<150)	
					{
						del("study/fight_exp");
						add("level",1);
						set("combat_exp",CChar::Level2Exp(query("level")));
						LONG exp = CChar::Level2Exp(query("level") + 1) - CChar::Level2Exp(query("level"));
						set("study/level_exp",int(exp/25));
						add("age",1);
						
						CMapping * skills =query_skills();
						CVector v;
						skills->keys(v);
						for(int i=0; i<v.count(); i++)
						{
							(*skills)[v[i]] += 1;
						}
						add("max_hp",80+query("con"));
						set("hp",query("max_hp"));
						set("eff_hp",query("max_hp"));							
						add("max_mp",100);
						set("mp",query("max_mp"));
						add("mp_factor", 2);
						
						FlushMyInfo();
						player->set("lj/tielao/age",query("age"));
						player->set("lj/tielao/level",query("level"));
						player->set("lj/tielao/str",query("str"));
						player->set("lj/tielao/dex",query("dex"));
						player->set("lj/tielao/int",query("int"));
						player->set("lj/tielao/con",query("con"));
						player->set("lj/tielao/per",query("per"));
						player->set("lj/tielao/combat_exp",query("combat_exp"));
						exp_reward=query("level")*(120+random(120));
						player->set("lj/tielao/level_exp",query("study/level_exp"));
						player->add("combat_exp",exp_reward);
						player->UpdateMe();

						tell_room(environment(),snprintf(msg, 255,"$HIR%s�����ˣ��ȼ����Ϊ%d����\n",name(1),query("level")));
						tell_object(player, snprintf(msg, 255,"\n\n$HIR�㱣�������й��������%d��ľ��齱����\n\n",exp_reward));
					}
				}
				if(random(2))
				{
					if(query("level")==15 && !player->query("lj/tielao/15"))
					{
						tell_object(player, "\n$HIR���Ѷ���˵������С���ѣ��⼸����ȴ���������������");
						tell_object(player, "$HIR��ɽ������ƽ�����˵�л����������������������պ���в�������");
						tell_object(player, "$HIR��ҡҡ�ֶ�����˵���������Ѵ��������������£������Ҿȡ���������ȡЦ���ҡ���");
						tell_object(player, "$HIR���ѳ�����ɫ���������������ڹ������˻�����Ψ�Ҷ��𹦣�������󣬵�ÿ��ʮ�꣬ȴҪ���ϻ�ͯһ�Σ�����ȫ�ޡ�");
						tell_object(player, "$HIR��������ʮ��������˱�����������ظ�����͹����������ȴ�Ǿ������ѡ���");
						if(player->query_skill("bahuang_gong",1)<400 && player->query_skill("bahuang_gong",1))
						{
							player->set_skill("bahuang_gong",player->query_skill("bahuang_gong",1)+1);
							player->add("pro/skill/bahuang_gong",1);
							player->FlushMySkill(player);
							tell_object(player, "\n\n$HIR���ܵ�����ָ�㡰�˻�����Ψ�Ҷ��𹦡�������ѧ�������˸���һ��ε�����\n\n");
						}
						else
						{
							player->add("combat_exp",1000);
							player->UpdateMe();
							tell_object(player, "\n\n$HIR���ܵ�����ָ�㡰�˻�����Ψ�Ҷ��𹦡�������ѧ�������˸���һ��ε����,������1000��ľ��顣\n\n");
						}
						player->set("lj/tielao/15",1);
					}
					if(query("level")==20 && !player->query("lj/tielao/20"))
					{
						if(DIFFERSTR(player->querystr("gender"), "Ů��"))
						{
							add("per",1);
							tell_object(player, "\n$HIR���Ѷ���ȵ�����С�ӣ����������ѣ���");
							tell_object(player, "$HIR�㿴��������ɫ���ޡ��۲�ӯӯ��ֱ�Ǹ���ò�Ĵ���������");
							tell_object(player, "$HIR���������ǰ��ǰ���ջ���λС���ӣ���������λ������Ů���ܲ��׿��²�̫���㡭����");
							tell_object(player, "$HIR��������һЦ������������˫���κ죬��ȻЦ����");
							tell_object(player, "$HIR�������ظ���С�ӣ����ѽ����Ѿ�ʮ���ˣ���������һ��Ƥ�Ұ��ˣ������ں���Щ�����࣡��");
							tell_object(player, "$HIR������һ�������������ǰ����ѵ���ǣ���");
							
							if(player->query("int")<30 && !player->query("pro/lj/int") && !random(20))
							{
								player->add("int",1);
								player->add("pro/lj/int",1);
								player->UpdateMe();
								tell_object(player, "\n\n$HIR���ܵ�����ָ�㡰�������������ǻ������ˡ�\n\n");
							}
							else
							{
								player->add("combat_exp",1000);
								player->UpdateMe();
								tell_object(player, "\n\n$HIR���ܵ�����ָ�㡰��������������1000����������ʾ��顣\n\n");
							}
							player->set("lj/tielao/20",1);
						}
					}
					if(query("level")==35 && !player->query("lj/tielao/35"))
					{
						
						add("per",1);
						tell_object(player, "\n$HIR�����������ȴ�������յ���ϲ��ɫ����������Щ��̾������˵����");
						tell_object(player, "$HIR����������Ȼ���������ڹ����絼�������޷����󣬵���ʵ���Ҷ�ʮ�������걾�л���ָ����Σ���������");
						tell_object(player, "$HIR������һ�����¼��ĳ�ң��������ֶΰ������ң������߻���ħ����Զ���ܳ���");
						tell_object(player, "$HIR�ɺ��Ǽ����书����Ҳ������£���ʮ�����໥֮�䶼�κβ��˶Է���");
						tell_object(player, "$HIR������һ�����������˹�֮����׷ɱ�ң���������֮ʱҪ�ر�С���ˡ���");
						
						player->add("combat_exp",1000);
						player->UpdateMe();
						player->set("lj/tielao/35",1);
						tell_object(player, "\n\n$HIR���˽⵽���ѵġ�����ͯ�������ɣ�����������1000��Ľ������顣\n\n");
					}
				}
				if(!random(player->query("int")-5)  && !player->query_temp("fight/is_fighting") && !(environment())->query("no_fight") && DIFFERSTR((environment())->querystr("area"), "house"))
				{
					if(query("level")>60 )
					{
						if(query("level")<75)
						{
							CNpc * kill_tielao = load_npc("lj_liqiuhen");
							kill_tielao->move(environment());
							
							if(EQUALSTR(player->querystr("family/family_name"), "���չ�"))
								kill_tielao->set("combat_exp",int(query("combat_exp")*0.6));
							else
							{
								kill_tielao->set("combat_exp",int(query("combat_exp")*1.2));
								kill_tielao->set("max_mp",int(query("max_mp")*1.1));
								kill_tielao->set("mp",int(query("mp")*1.1));
								kill_tielao->set("apply/armor", 280);
								kill_tielao->set("apply/damage", 150);
							}
							
							if(!player->query("lj/tielao/liqiuhen"))
							{
								message_vision("\n$HIR����ͻȻ��ɫһ������ɫ�������Ǽ�������׷���ˡ�",this);
								message_vision("$HIR��Ȼ������ǰ������һ������ȵİ���������ˣ�ԭ�����������ѵ����У����Ļ�̫������ۡ�",this);
								message_vision("$HIRֻ������۵���ǳЦ������ʦ�㣬�������ҵȵ������ˣ�����֮�𣬽��ձر�����\n",this);
								message_vision("���������ɽ���ѷ����˹�����\n",this);
								player->set("lj/tielao/liqiuhen",1);
							}
							else
							{
								message_vision("����۵���ǳЦ������ʦ�㣬�㲻Ҫ���Ƕ�����ѽ�������õ�ʵ���Ǻ��������أ���",this);
								message_vision("���������ɽ���ѷ����˹�����\n",this);
							}
							if(EQUALSTR((kill_tielao->environment())->name(1), environment()->name(1))
								&& EQUALSTR((player->environment())->name(1), environment()->name(1)))
							{
								((CUser *)kill_tielao)->Ready_PK();
								((CUser *)this)->Ready_PK();
								((CUser *)player)->Ready_PK();
								player->kill_ob(kill_tielao);	
								this->kill_ob(kill_tielao);	
								kill_tielao->kill_ob(this);
							}
						}
					}
					else if(query("level")>50)
					{
						static char ljdongzhu[10][20]={"lj_duanmufang","lj_ganshuangqing","lj_hefueren","lj_hedongzhu",
							"lj_andongzhu","lj_qingdaozhu","lj_qudaozhu","lj_yundaozhu","lj_zhuyadaguai","lj_zhuyaerguai"};
						
						CNpc * kill_tielao = load_npc(ljdongzhu[random(10)]);
						kill_tielao->move(environment());

						kill_tielao->set("mp",int(query("mp")*1.2));
						kill_tielao->set("max_mp",int(query("max_mp")*1.2));
						kill_tielao->del("mp_factor");

						message_vision(snprintf(msg, 255,"\n$HIR��Ȼ����ܳ�һ�ˣ���ϸһ����ԭ����%s��",kill_tielao->name(1)),this);
						message_vision(snprintf(msg, 255,"%s����ɽ���ѷ����˹�����\n",kill_tielao->name(1)),this);
						if(EQUALSTR((kill_tielao->environment())->name(1), environment()->name(1))
							&& EQUALSTR((player->environment())->name(1), environment()->name(1)))
						{
							((CUser *)kill_tielao)->Ready_PK();
							((CUser *)this)->Ready_PK();
							((CUser *)player)->Ready_PK();
							player->kill_ob(kill_tielao);	
							this->kill_ob(kill_tielao);	
							kill_tielao->kill_ob(this);
						}
					}
					else if(query("level")>30)
					{
						CNpc * kill_tielao = load_npc("lj_shuxia1");
						kill_tielao->move(environment());

						kill_tielao->set("mp",int(query("mp")*1.1));
						kill_tielao->set("max_mp",int(query("max_mp")*1.1));
						kill_tielao->del("mp_factor");

						message_vision(snprintf(msg, 255,"\n$HIR��Ȼ����ܳ�һ�ˣ���ϸһ����ԭ����%s��",kill_tielao->name(1)),this);
						message_vision(snprintf(msg, 255,"$HIR%s����������ѣ���ϲ������С�ӣ������ҵ������ˣ�����",kill_tielao->name(1)),this);
						message_vision(snprintf(msg, 255,"%s����ɽ���ѷ����˹�����\n",kill_tielao->name(1)),this);
						if(EQUALSTR((kill_tielao->environment())->name(1), environment()->name(1))
							&& EQUALSTR((player->environment())->name(1), environment()->name(1)))
						{
							((CUser *)kill_tielao)->Ready_PK();
							((CUser *)this)->Ready_PK();
							((CUser *)player)->Ready_PK();
							player->kill_ob(kill_tielao);	
							this->kill_ob(kill_tielao);	
							kill_tielao->kill_ob(this);
						}
					}
				}
			}
		}
	}
	return 0;
}

virtual LONG Query(int nAttr)
{
	if(nAttr == CAN_GET)
		return 1;

	return CNpc::Query(nAttr);
}

virtual int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "get") == 0 )
		return do_get(me);
	else if( strcmp(comm, "drop") == 0)
		return do_drop(me);
	else if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	 )
	{
		message_vision("$n���Ŵ�������$N���Ծ���˵������������Ҳ���ǣ�$N��Ļ����ˣ�", me, this);
		me->start_busy(2);
		return 1;
	}
	else if(strcmp(comm, "cast") == 0 && userp(me) )
	{
		message_vision("$n���Ŵ�������$N���Ծ���˵������������Ҳ���ǣ�$N��Ļ����ˣ�", me, this);
		me->start_busy(2);
		return 1;
	}

	if(me->query("lj/renwu8") )
	{
		if(strcmp(comm, "zhuxu") == 0 && !me->query("lj/talk1"))
		{
			tell_object(me, "\n$HIR��ɽ���ѣ���Ŷ�����Ǹ���������С���н����������ҵģ�����������ҿ��������˰ɣ���\n");
			me->set("lj/talk1",1);
			return 1;
		}
		else if(strcmp(comm, "backlj") == 0 && !me->query("lj/talk2"))
		{
			if(!query("lj/renwu9"))
			{
				tell_object(me, "\n$HIR��ɽ���ѣ����Ҵ˿��񹦴���������ϴ��Ǹ�ŧ��Ҳ��ʤ���ң����������Ķ�ͷһ���������չ����ҡ���");
				tell_object(me, "$HIR��ɽ���ѣ�������������ټ�󽭺��ϱܱܷ�ͷ�������񹦻ظ������г��˺��ٻع����١���\n");
			}
			else
			{
				tell_room(me,"$HIR��ɽ���Ѷ���˵����������Ȼ���Ǽ��˷��֣������������ڶ࣬����������������Ȼ���Ի�����");
				tell_room(me,"$HIR���֮��ֻ�ñ������ţ���Σ�յĵط������ȫ�ĵط���");
				tell_room(me,"$HIR��ǰ�Ҵ�ɱ��ʱ�����������Ļʹ��ĵ��±����ж������ʱ����ȥ�Ǵ��ܱܰɣ���\n");
			}
			return 1;
		}
		else if(strcmp(comm, "ask_tielao") == 0 )
		{
			char msg[255];
			tell_object(me, "\n$HIR----------------------------------��ɽ��������----------------------------------");
			tell_object(me, snprintf(msg, 255, "        $HIR������%d �ǻۣ�%d ���ݣ�%d ���ʣ�%d",query("str"),query("int"),query("dex"),query("con")));
			tell_object(me, snprintf(msg, 255,"        $HIR������%d �ȼ���%d",query("per"),query("age")));
			tell_object(me, snprintf(msg, 255, "        $HIRhp��%d max_hp��%d mp:%d max_mp��%d",query("hp"),query("max_hp"),query("mp"),query("max_mp")));
			if(query("level")<=30)
				tell_object(me, snprintf(msg, 255,"        $HIR��ǰ���飺%d �������辭�飺%d",query("study/fight_exp"),query("level")*9));
			else
				tell_object(me, snprintf(msg, 255,"        $HIR��ǰ���飺%d �������辭�飺%d",query("study/fight_exp")+query("study/shiti")*query("level")*3,query("study/level_exp")));
			tell_object(me, snprintf(msg, 255,"        $HIR����������%d  ������ʧ��ʣ�������%d",query("lost")-me->query("lj/tielao/count"),me->query("lj/tielao/count")));
			tell_object(me, "$HIR--------------------------------------------------------------------------------\n");
			return 1;
		}
		else if(strcmp(comm, "ask_tielaowg") == 0 )
		{
			FlushMySkill(me);
			return 1;
		}
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_get(CChar * me)
{   
	if(query("age")<14 && me->querymap("lj")&& (!query("owner")||query("owner")==atoi(me->id(1))))
	{
		move(me);
		me->set_temp("no_fei",1);
		if(!query("owner")||(!me->query("lj/renwu8") && me->query("lj/renwu7") && query("owner")==atoi(me->id(1))) )
		{
			set("owner",atoi(me->id(1)));
			me->set_temp("lj/tielao",1);
			me->set("lj/tielao/count",query("lost"));
			me->set("lj/tielao/name",name(1));
			me->set("lj/tielao/id",id(1));
			me->set("lj/tielao/���",1);
			me->set("lj/tielao/age",query("age"));
			me->set("lj/tielao/level",query("level"));
			me->set("lj/tielao/str",query("str"));
			me->set("lj/tielao/dex",query("dex"));
			me->set("lj/tielao/int",query("int"));
			me->set("lj/tielao/con",query("con"));
			me->set("lj/tielao/per",query("per"));
			me->set("lj/tielao/combat_exp",query("combat_exp"));
			me->set("lj/tielao/level_exp",query("level")*3);
			remove_call_out(do_restore);
			call_out(do_restore, 1);
		}
	}
	
	return 1;
}

int do_drop(CChar * me)
{
     if(move(me->environment()) ) 
	 {
		message_vision("$N��$n�ӻ������������", me, this);
		set_leader(me);
		me->delete_temp("no_fei");
		remove_call_out(do_restore);
		if(me->query("lj/tielao/���") && query("drop") && !me->query_temp("fight/is_fighting"))
		{
			tell_object(me, "\n$HIR���ʧɫ����æ�������Ůͯ���¡�ֻ�������ֶ��������鴦����¶������������������ʡ�");
			tell_object(me, "$HIR�㱧ȭ��Ҿ����̽�ʵ�����ǰ�������ܷ��������");
			tell_object(me, "$HIRֻ������һЦ���������Ҿ��Ǹղ��ǰ�С��Ҫ�ҵ���--���չ����ˣ���ɽ���ѡ���");
			tell_object(me, "\n$HIR���Ȼ���򣺡�ԭ�������д�˵��ɽ���������ܷ��ϻ�ͯ����Ŀ����ѹ֣�һ����������Ҳ��֮�ݼ�����˲ű����ϴ���Ѿ��²��ȥ����\n");
			set_name("��ɽ����",  "tie lao");
			FlushMyInfo();
			me->del("lj/tielao/���");
			me->del("lj/renwu7");
			me->set("lj/renwu8",1);
			del("run/count");
			del("drop");
			CContainer * env = load_room("���ն�����");
			char msg[255];
			env->set(snprintf(msg,255,"%s",me->id(1)),1);
		}
		return 1;
     }
	 return 0;
}


static void do_restore(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * npc = (CChar *)ob;
	CUser * player;
	snprintf(msg,255,"%d",npc->query("owner"));
	player=find_online(msg);
	if(!player)
	{
		CContainer * env = load_room("���ն�����");
		if(env->query(msg))
			env->del(msg);
		destruct(npc);
	}
	else
	{
		if(npc->query("run/count")<4 && player->query("lj/tielao/���"))
		{
			if(DIFFERSTR(npc->querystr("run/name"),(player->environment())->name(1)))
			{
				npc->set("run/name",(player->environment())->name(1));
				npc->add("run/count",1);
			}
			npc->call_out(do_restore, 1);
		}
		else
		{
			tell_object(player, "\n$HIRͻȻ���㱳�������ϵ�Ů�������������콫�����ҷ����������ȻҪ��Ӣ�ۣ��ֺα�����ô�죡��");
			tell_object(player, "$HIR�������Ĺˣ�ȴû������Ӱ���ѵ������˾������֣�");
			tell_object(player, "\n$HIR���������������Ų���뿴������Ƿ����˸��٣�ȴ��������������Ӱ������һ�˵ġ�");
			tell_object(player, "$HIR��е�һ��ë���Ȼ�����ķ��������������ǰ�����Ṧ������Ϊ������ƽ�����������书��΢�Ҳ���ǰ���ټ�������ǰ������һ�𡣡�");
			tell_object(player, "$HIRȴ�������Ŵ����������������Ҿͱ��㱳�ڱ����أ���");
			npc->set("drop",1);
		}
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("lj/renwu8") && !me->query("lj/talk1") && query("owner")==atoi(me->id(1)))
	{
		AddMenuItem("����", "$0zhuxu $1", me);
		SendMenu(me);	
		return 1;
	}
	else if(me->query("lj/renwu8") && !me->query("lj/talk2") && query("owner")==atoi(me->id(1)))
	{
		AddMenuItem("�����չ�", "$0backlj $1", me);
		SendMenu(me);	
		return 1;
	}
	if(me->query("lj/renwu8") && query("owner")==atoi(me->id(1)))
	{
		AddMenuItem("���Ѹ�������", "$0ask_tielao $1", me);
		AddMenuItem("�����书����", "$0ask_tielaowg $1", me);
		SendMenu(me);	
		return 1;
	}
	
	return CNpc::do_talk(me, ask);
}

virtual void die()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * player;
		snprintf(msg,255,"%d",query("owner"));
		CContainer * env = load_room("���ն�����");
		if(env->query(msg))
			env->del(msg);
		player=find_online(msg);
		if(player)
		{
			player->add("lj/tielao/count",-1);
			player->delete_temp("lj/tielao");
			if(player->query("lj/tielao/count")<=0)
			{
				player->del("lj/tielao");
				if(player->query("lj/renwu7"))player->del("lj/renwu7");
				if(player->query("lj/renwu8"))player->del("lj/renwu8");
				player->set("lj/renwu_lost",2);
				message_vision(snprintf(msg, 255, "$HIR����%s�����ĵ��£�$N���ĺ�Ȼ��������ʹ���·�����ʧȥ�����˰�ı�����",name(1)),player);
			}
		}
	}
	CNpc::die();
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	if(!who->querymap("lj")) return 0;

	if(DIFFERSTR(ob->querystr("name"), "�ɺ�ҩ") && DIFFERSTR(ob->querystr("name"), "�ϳ���")
		&& DIFFERSTR(ob->querystr("name"), "�̲Ϸ�") && DIFFERSTR(ob->querystr("name"), "��ȸ��")
		&& DIFFERSTR(ob->querystr("name"), "���ߵ�") && DIFFERSTR(ob->querystr("name"), "���ߵ�")
		&& DIFFERSTR(ob->querystr("name"), "�׶���") && DIFFERSTR(ob->querystr("name"), "���ߵ�") 
		&& DIFFERSTR(ob->querystr("name"), "����ͭ��") && DIFFERSTR(ob->querystr("name"), "����ͭ��")
		&& DIFFERSTR(ob->querystr("skill_type"), "sword") && DIFFERSTR(ob->querystr("name"), "��ҩ")
		&& DIFFERSTR(ob->querystr("name"), "���") && DIFFERSTR(ob->querystr("name"), "������")
		)
		return 0;

	if(EQUALSTR(ob->querystr("name"), "����ͭ��"))
	{
		message_vision("\n$HIR��ɽ���ѣ�����˵�����㲻���ǿ��������Ѿ͸���ͭ�˰ɣ��ⶫ�����һ����أ������ױ������к��ʰɣ���",who);
		message_vision("$HIR$N������^O^\n",who);
		destruct(ob);
	}
	else if(EQUALSTR(ob->querystr("name"), "���")&& !query("���"))
	{
		message_vision(snprintf(msg, 255, "$HIR��ɽ���ѷ���%s��ֻ������ȫ����һ��ů���ӵ���ֱ��������",ob->name(1)),who);
		set("max_hp",query("max_hp")*2);
		set("hp",query("max_hp"));
		set("eff_hp",query("max_hp"));
		set("���",1);
		destruct(ob);
	}
	else if(EQUALSTR(ob->querystr("name"), "������") && query("owner")==atoi(who->id(1)))
	{
		message_vision(snprintf(msg, 255, "$HIR��ɽ���ѷ���%s����Ѹ�ٽ����ڸ�����ɢ�����������뵤��������澭������",ob->name(1)),who);
		if(who->query("lj/tielao/count")< query("lost"))
			who->add("lj/tielao/count",1);
		destruct(ob);
	}
	else if(EQUALSTR(ob->querystr("name"), "��ҩ") && query("hp")<=query("max_hp"))
	{
		message_vision(snprintf(msg, 255, "$HIR��ɽ���ѷ���%s����ʱ�������",ob->name(1)),who);
		if(query("hp")<=query("max_hp")-500)
		{
			add("hp",500);
			add("eff_hp",500);
		}
		else
		{
			set("hp",query("max_hp"));
			set("eff_hp",query("max_hp"));
		}
		destruct(ob);
	}
	else if(EQUALSTR(ob->querystr("skill_type"), "sword") )
	{
		if(query("level")>=40)
		{
			CContainer * weapon = query_weapon();
			if(weapon)
			{
				destruct(weapon);
			}
			set("wuqi",ob->querystr("base_name"));
			carry_object(ob->querystr("base_name"))->wield();
			message_vision(snprintf(msg, 255, "$HIR��ɽ���ѡ�ৡ���һ��װ������%s��",ob->name(1)),who);
			destruct(ob);
		}
	}
	else		
	{
		destruct(ob);
		if(EQUALSTR(who->querystr("gender"), "����"))
		{
			message_vision("\n$HIR��ɽ���ѣ�����ô���岻��ʹ���ˣ����Ρ�����ô������˵�С�����֢����",who);
			message_vision("$HIR$N�������� ���� ������\n",who);
		}
		else if(EQUALSTR(who->querystr("gender"), "Ů��"))
		{
			message_vision("\n$HIR��ɽ���ѣ�����ôȫ�������ķ����ң���������Ĳ��㡭��ÿ����������ô���죡��",who);
			message_vision("$HIR$N�������� ���� ������\n",who);
		}
		else
		{
			message_vision("\n$HIR��ɽ���ѣ�����ô���嶯�������ˣ�ι��С�ӣ��㲻���ǿ�����̫Ư������ʲô�Ƿ�֮��ɣ�����",who);
			message_vision("$HIR$N�������� ���� ������\n",who);
		}
	}

	return 1;
}


static void do_wujian(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CUser * player;
	snprintf(msg,255,"%d",me->query("owner"));
	player=find_online(msg);
	if(!player)
	{
		CContainer * env = load_room("���ն�����");
		if(env->query(msg))
			env->del(msg);
		destruct(me);
	}
	else if(player->query_temp("lj/renwu82"))
	{
		switch(player->query_temp("lj/wujian"))
		{
		case 0:
			tell_object(player, "\n$YEL������һ��--------$HIR������������$YEL--------\n\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 1:
			tell_object(player, "$YEL                     һ����\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 2:
			tell_object(player, "$YEL                  ��ͽڵ�����");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 3:
			tell_object(player, "$YEL                  μ�ǳ������᳾��");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 4:
			tell_object(player, "$YEL                  ����������ɫ�¡�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 5:
			tell_object(player, "$YEL                  Ȱ������һ���ƣ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 6:
			tell_object(player, "$YEL                  ���������޹��ˣ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 7:
			tell_object(player, "$YEL                  ˪ҹ��˪����\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 8:
			tell_object(player, "$YEL                  ���У����У�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 9:
			tell_object(player, "$YEL                  ��;Խ�ɹؽ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 10:
			tell_object(player, "$YEL                  ����۴��� ");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 11:
			tell_object(player, "$YEL                  ����������������");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 12:
			tell_object(player, "$YEL                  �������������䣬 ");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 13:
			tell_object(player, "$YEL                  �����䡣\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 14:
			tell_object(player, "$YEL                      ������\n ");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;	
		case 15:
			tell_object(player, "$YEL                  μ�ǳ������᳾�� ");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 16:
			tell_object(player, "$YEL                  ����������ɫ�¡�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 17:
			tell_object(player, "$YEL                  Ȱ������һ���ƣ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 18:
			tell_object(player, "$YEL                  ���������޹��ˣ�\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 19:
			tell_object(player, "$YEL                  �������������룬");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 20:
			tell_object(player, "$YEL                  ���մ��");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
		case 21:
			tell_object(player, "$YEL                  �޸��ศ�ʡ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 22:
			tell_object(player, "$YEL                  �л����л���");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 23:
			tell_object(player, "$YEL                  ˼��ʮ��ʱ����\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 24:
			tell_object(player, "$YEL                  ���̸�һ��");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
		case 25:
			tell_object(player, "$YEL                  ˭����˭����");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 26:
			tell_object(player, "$YEL                  ˭������");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 27:
			tell_object(player, "$YEL                  �ճ����ճ���\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 28:
			tell_object(player, "$YEL                      ������\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 29:
			tell_object(player, "$YEL                  μ�ǳ������᳾��");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 30:
			tell_object(player, "$YEL                  ����������ɫ�¡�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 31:
			tell_object(player, "$YEL                  Ȱ������һ���ƣ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 32:
			tell_object(player, "$YEL                  ���������޹��ˣ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 33:
			tell_object(player, "$YEL                  ���ݱ�����\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 34:
			tell_object(player, "$YEL                  ּ�ƣ�ּ�ƣ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 35:
			tell_object(player, "$YEL                  δ�������Ѵ���");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 36:
			tell_object(player, "$YEL                  �س��S���س��S");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 37:
			tell_object(player, "$YEL                  ��������ꥣ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 38:
			tell_object(player, "$YEL                  ���ü���Ѳ��\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 39:
			tell_object(player, "$YEL                  ��Ѳ�о���");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 40:
			tell_object(player, "$YEL                  ����������");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 41:
			tell_object(player, "$YEL                  �޾����˸С�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 42:
			tell_object(player, "$YEL                  ������ˮ��Զ����");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 43:
			tell_object(player, "$YEL                  �����к��ۡ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 44:
			tell_object(player, "$YEL                  ���ؽ����ؽ�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 45:
			tell_object(player, "$YEL                  ����Ƶ�������ף�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 46:
			tell_object(player, "$YEL                  �����ס�");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 47:
			tell_object(player, "$YEL                  �棡�ӽ�һ��");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 48:
			tell_object(player, "$YEL                  ������˼����Ƶ��");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 49:
			tell_object(player, "$YEL                  ����������");
			player->delete_temp("lj/wujian");
			player->delete_temp("lj/renwu82");
			me->set("chat_chance", 30);
			player->set("hp",player->query("eff_hp"));
			player->enable_player();
			player->environment()->del("no_fight");
			if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
			{
				player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
				player->add("pro/skill/liuyang_zhang",1);
				player->add("lj/pro/skill/liuyang_zhang",1);
				
				if(player->query_skill("music",1)<220 && player->query_skill("music",1))
				{
					player->set_skill("music",player->query_skill("music",1)+1);
					player->add("pro/skill/music",1);
					player->add("lj/pro/skill/music",1);
					tell_object(player, "\n\n$HIR�㿴�����ѵ��ֻӽ��������裬�ԡ���ɽ�����Ƶ���ʽ�������������������ⲻ֪���������˸���һ��ε�����");
					tell_object(player, "$HIR���������ѵĽ����Ȼ��ֹ���������Ҳͣ��������������ֵ�����Ҳ�����ˡ�\n\n");
				}
				else
					tell_object(player, "\n\n$HIR�㿴�����ѵ��ֻӽ��������裬�ԡ���ɽ�����Ƶ���ʽ�������������������ⲻ֪���������˸���һ��ε�����\n\n");
				player->FlushMySkill(player);

			}
			else
			{
				player->add("combat_exp",1000);
				player->UpdateMe();
				tell_object(player, "\n\n$HIR�㿴�����ѵ��ֻӽ��������裬�ԡ���ɽ�����ơ����˸���һ��ε�����������1000��ľ��顣\n\n");
			}
			break;
		}
	}
}
NPC_END;
