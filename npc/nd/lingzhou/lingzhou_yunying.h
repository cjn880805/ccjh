/*
string *list1 = ({ "杀手", "杀手统领", "指挥使", "副总管", "总管" }); //-->总堂副总管-->护国都尉-->护国将军-->护国大将军
string *list2 = ({ "细作", "细作统领", "指挥使", "副总管", "总管" }); // 总堂副总管-->护国参议-->护国军师-->护国公

int do_shengji();
int kill_stranger( object who );
int kill_stranger1( object who );
int try_rutang();
int start_rutang( object me );
int do_jieshao( string arg );
int do_choose( string arg );
int do_lingpai( string arg );
string dir_random();
string to_english( string arg );
int read_task( object me );
int crash( object ob );
*/
//一品堂总堂总管

//yunying.c

//sound 2001-07-17

NPC_BEGIN(CNlingzhou_yunying);

virtual void create()
{
	set_name("赫连雨鹰", "helian yunying");
	set("title", "一品堂总堂总管");
	set("gender", "男性" );
	set("age", 45);
	set("str", 200);
	set("per", 30);
	set("icon",general);
	set("long", "西夏一品堂的总管，是赫连铜树的心腹和过密的兄弟。主持一品堂日常大事。");
	set("combat_exp", 300000);
	set("social_exp", 120000);
	
//	set_inquiry("升级", "(:do_shengji:)");
	set_inquiry("入堂", "入堂必须有本堂两名资深弟子推荐介绍");
	
	set("chat_chance", 1);

//	carry_object("zangqing_sipao" )->wear();
//	carry_object("xuese_pifeng" )->wear();
}

virtual char *chat_msg()
{
	return "赫连雨鹰淡淡地笑着，一副目空一切的样子。";
}
/*
void init()
{
	add_action("try_rutang","join");
	add_action("do_jieshao","jieshao");
	add_action("do_jieshao","tuijian");
	add_action("do_choose", "xuanze");
	add_action("do_lingpai","shenqing");
	add_action("read_task", "task");
}			   

int accept_fight(object me)
{
	message_vision("\n赫连云鹰奇怪地打量了$P一眼，忽然大笑了起来。\n", me );
	message_vision("震得整个房顶仿佛都颤抖了起来。\n\n", me );
	return 0;
}

int accept_object(object who, object ob )
{
	
	object lingpai;
	string dir1,dir2;
	
	dir1 = dir_random();
	dir2 = to_english( dir1 );
	
	if( who->query("yipin_task/keyname") == "取" && 
		who->query("yipin_task/obname") == ob->query("name") )
	{
		if ( userp( ob ) )
		{
			message_vision("$YEL赫连云鹰对$P大喝一声，你敢糊弄老夫！\n$COM", who );
			call_out("kill_stranger",1,who);
			return 0;
		}
		tell_object( who, "$YEL赫连云鹰点头到，好！\n$COM");
		YIPIN_D->end_yipin_task("取", who, ob );
		return 1;
	}
	
	if( who->query("yipin_task/keyname") == "活捉" && 
		who->query("yipin_task/obname") == ob->query("name") )
	{
		if ( userp( ob ) )
		{
			message_vision("$YEL赫连云鹰对$P大喝一声，你敢糊弄老夫！\n$COM", who );
			call_out("kill_stranger",1,who);
			return 0;
		}
		if ( ( who->query("mud_age") - who->query("lnwm/yipin/牢房") ) < 600 )
		{
			tell_object( who, "赫连云鹰看了你一眼：我刚刚不是让你把犯人送到牢里去了么？\n");
			return 0;	   
		}
		tell_object( who, "$YEL赫连云鹰点头到，干的不错。\n$COM");
		tell_object( who, "$YEL你拿上这个牌子，把犯人送到地下牢房去。\n$COM");
		lingpai=new(__DIR__ "obj/laofangling");
		lingpai->set("持令人",who->query("id") );
		lingpai->move(who);
		tell_object( who,"赫连云鹰低声对你说：在零一阁推"+dir1+"边的柱子就可进入地下。\n");
		who->set_temp("lnwm/enter_yipin/中",dir1);
		who->set_temp("lnwm/enter_yipin/英",dir2);	 
		who->set("lnwm/yipin/牢房", who->query("mud_age") );					
		return 0;
	}
	if ( ob->query("id") != "rutang xin" )
	{
		message_vision("赫连云鹰奇怪地看了$P一眼，说：你给我这个做什么？\n", who );
		return 0;
	}
	else
	{
		if ( ob->query("持信人") == "奸细" )
		{
			message_vision("赫连云鹰只看了一下信皮，就冲$P冷笑了一声：又是个没用的东西！\n你拿给长在将军的东西是谁给的？！来人，拿下！\n", who );
			call_out("kill_stranger",1,who);
			return 1;
		}
		if ( who->IsMemberOf("yipin") )
		{
			tell_object( who, "你已经是一品堂的人了。\n");
			return 0;
		}
		if ( ob->query("持信人") != who->query("id") )
		{
			message_vision("赫连云鹰翻了翻书信，然后上下打量了$P一番。忽然冷笑了一声：\n", who );
			message_vision("这真是赫连长在将军亲手交给你的么？！！！来人！！拿下！！\n", who );
			call_out("kill_stranger",1,who );
			return 1;		
		}
		else
		{
			message_vision("赫连云鹰看了书信，又打量了$P几眼。点了点头：\n", who );
			message_vision("好，既是长在将军推荐，定错不了。\n", who );
			call_out("start_rutang",1,who );
			return 1;
		}
	}
}

int do_shengji()
{
	object me = this_player();
	int max_score, i, jibie;
	
	max_score = 1;
	i = 1;
	if( !me->IsMemberOf( "yipin" ) )
	{
		command( "say 你是哪儿来的？和我们一品堂没有关系！" );
		return 1;
	}
	if ( me->query("lnwm/yipin/要求升级") > 10 )
	{
		message_vision("赫连云鹰突然瞪了$N一眼：你这是第几次来打听升级的事了？哼！\n", me );
		me->AddZuzhiScore("yipin", -50);
		me->delete("lnwm/yipin/要求升级");
		return 1;
	}
	jibie = me->ZuzhiTouxianJibie( "yipin" );
	while( i <= jibie )
	{
		max_score = max_score * 2;
		i++;
	}
	max_score = max_score * 200+ 1000*( jibie+1 ); // here refined by lnwm 
	//  这样的话，升级需要的score是 1200(杀手), 2400(杀手统领), 3800(指挥使), 5600(副总管),  
	if( me->ZuzhiScore("yipin") >= max_score )
		//	   && me->query( "yipin_tang_quest_done" ) > jibie )
	{			   
		command( "say 好！你这段时间干的不错，可以担当更重要的职务。" );
		//me->add( "yipin/zuzhi_dengji_num", 1 );
		me->IncreaseZuzhiTouxian( "yipin", 1 );
		message_vision( "祝贺$N成为" + me->ZuzhiName( "yipin" ) + 
			me->ZuzhiTouxian( "yipin" ) + "!!\n", me  );
		LOG_D->do_log( me, sprintf( "你在%s中获得晋升，成为一名%s。", me->ZuzhiName( "yipin" ),
			me->ZuzhiTouxian( "yipin" ) ) );
		command( "say 今后更需多多努力！！" );
		me->delete("lnwm/yipin/要求升级");
		me->delete("lnwm/yipin/领玄武令");
		return 1;
	}
	message_vision("赫连云鹰冷冷地看了$N一眼：你做得还差的远！不要随便在我这里提升级的要求！\n", me );
	me->add("lnwm/yipin/要求升级",1);
	return 1;	
}	

int start_rutang( object me )
{
	object ob = this_object();
	
	message_vision( GRN @LONG
		
		$N对$n说:
		
		入本堂的弟子一开始就必须选择一个分堂加入。
		你可以选择(xuanze)「玄阳堂」和「玄才堂」中的一个。「玄阳堂」是本堂中杀
		手效力的分堂，堂中弟子应按照要求除掉危害本堂和我大夏国之人；「玄才堂」
		是本堂中卧底细作效力的分堂，堂中弟子要听从吩咐刺探有利于本堂和我大夏国
		的情报。凡功勋卓著、忠心耿耿的弟子都有机会升迁。比较起来，「玄阳堂」的
		弟子最终可以升到「护国大将军」的职位，荣宠有加；「玄才堂」的弟子则最终
		可以升到「护国公」的地位，那可是一言九鼎，位极人臣啊！怎么样？你想好了
		没有？
		
		LONG $COM, ob, me );
	me->set_temp("pending/一品/can_choose", 1);
	return 1;
}

int do_choose(string arg)
{
	object me;
	me = this_player();
	if( !(me->query_temp("pending/一品/can_choose" )) )
		return 0;
	if( !arg ||
		( arg != "玄阳堂" && arg != "玄才堂" && arg != "xuanyangtang" && arg != "xuancaitang" ) )
		return 0;
	me->delete_temp( "pending/一品/can_choose" );
	if( arg == "玄阳堂" || arg == "xuanyangtang" )
	{
		message_vision( "$CYN$N说道：弟子选玄阳堂吧。\n$COM", me );
		message_vision( "$YEL\n
			$N说道：好，那我就让你加入「玄阳堂」！你须得守我堂规，效忠大夏！\n
			$n跪倒在地，「咚咚咚」连磕三个响头。\n
			$COM", this_object(), me );
			tell_object( me, "恭喜你成为西夏「一品堂」下属「玄阳堂」徒众！\n" );
		me->JoinZuzhi("yipin","徒众","玄阳堂");
		me->set( "zuzhi/yipin_tang/zuzhi_dengji", "徒众" );
		me->set( "yipin/zuzhi_dengji_num", 0 );
		return 1;
	}
	message_vision( "$CYN$N说道：弟子选玄才堂吧。\n$COM", me );
	message_vision( "$YEL\n
		$N说道：好，那我就让你加入「玄才堂」！你须得守我堂规，效忠大夏！\n
		$n跪倒在地，「咚咚咚」连磕三个响头。\n
		$COM", this_object(), me );
		tell_object( me, "恭喜你成为西夏「一品堂」下属「玄才堂」徒众！\n" );
	me->JoinZuzhi("yipin","徒众","玄才堂");
	me->SetZuzhiScore("yipin",0);
	return 1;
}

int try_rutang()
{
	object me = this_player();
	
	if ( me->IsMemberOf("yipin") )
	{
		message_vision("$P向赫连云鹰拱手：卑职见过大人！\n",me);
		return 1;
	}
	
	if ( !( me->query("lnwm/yipin_tang/介绍人1") ) )
	{
		message_vision("赫连云鹰冷哼了一声：是谁介绍你来的？\n", me );
		return 1;
	}
	else if ( !( me->query("lnwm/yipin_tang/介绍人2") ) )
	{
		message_vision("赫连云鹰微微点了点头：你还需要另一个人的推荐。\n", me );
		return 1;
	}
	else
	{
		message_vision("赫连云鹰点了点头：好既有人推荐，那你就入堂吧。\n", me );
		me->delete("lnwm/yipin_tang/介绍人1");
		me->delete("lnwm/yipin_tang/介绍人2");
		call_out("start_rutang",1,me );
		return 1;
	}
}

int do_jieshao( string arg )
{
	object me, *inv;
	int i;
	
	me = this_player();
	
	if ( !arg )
	{
		tell_object( me, "你要介绍谁？\n");
		return 1;
	}
	
	if ( !me->IsMemberOf("yipin") )
	{
		message_vision("赫连云鹰微微一笑，对$P说：你搞错了吧？\n",me);
		return 1;
	}
	
	if ( arg == me->query("id") )
	{
		tell_object(me,"搞错了吧？推荐你自己？你以为你是毛遂呀。\n");
		return 1;
	}
	
	if ( me->ZuzhiScore("yipin") < 4000 )
	{
		message_vision("赫连云鹰对$P微微一笑：你对本堂的忠诚尚还不够，还没有推荐的资格。\n", me);
		return 1;
	}
	else
	{
		inv = all_inventory( environment(this_object() ) );
		
		for ( i=0; i < sizeof(inv); i++ )
		{
			if ( !userp(inv[i]) ) continue;
			if ( inv[i]->query("id") == arg )  
			{
				if ( inv[i]->IsMemberOf("yipin"))
				{
					message_vision("赫连云鹰道：此人已是本堂属下，无需推荐了。\n",me);
					return 1;
				}
				
				if ( !(inv[i]->query("lnwm/yipin_tang/介绍人1")) )
				{
					message_vision("$N向赫连云鹰推荐$n。\n",me,inv[i]);
					message_vision("赫连云鹰对$P点点头：我知道了。\n",me);
					inv[i]->set("lnwm/yipin_tang/介绍人1", me->query("id") );
					return 1;
				}
				else if ( (inv[i]->query("lnwm/yipin_tang/介绍人1")) != (me->query("id")) )
				{
					message_vision("$N向赫连云鹰推荐$n。\n",me,inv[i]);
					message_vision("赫连云鹰微笑着看看$P：你已得到两个人的推荐了。\n",inv[i]);
					inv[i]->set("lnwm/yipin_tang/介绍人2", me->query("id") );
					return 1;
				} 
				tell_object( me, "你已经推荐过这个人了。\n");
				return 1;
			}
		}
		tell_object( me, "你要介绍的人不在这里。\n");
		return 1;
	}
}

int refuse_killing( object me )
{
	me->apply_condition("kill_yipin",500);
	message_vision("赫连云鹰冷笑一声；竟敢有人在这里撒野，活得不耐烦了！\n", me );
	call_out("kill_stranger",1,me);
	return 1;
}

int kill_stranger( object me )
{
	int i;
	object *inv;
	
	inv = all_inventory( environment(this_object()) );
	
	message_vision("$CYN\n只见赫连云鹰手在案后一拍，$N脚下的地面竟移动了起来。。\n$COM", me );
	call_out("kill_stranger1",3,me );
	
	message_vision("\n赫连云鹰冷笑着，这人活的不耐烦了？！来人，拿下。\n",me );
	
	for(i = 1; i < sizeof(inv); i++)
	{
		if ( !userp( inv[i] )
			&&  inv[i] != this_object() 
			&& inv[i]->IsMemberOf("yipin")
			&& inv[i] != me )
		{
			inv[i]->kill_ob(me);
			me->fight_ob( inv[i] );
		}
	}
	return 0;
}

int kill_stranger1( object me )
{
	if( !present( me, environment( this_object() ) ) )
		return 0;
	
	if( me->query("combat_exp" ) < 50000 )
	{
		message_vision("$CYN$N脚下一软，地面豁然拉开一道翻版，$N一个跟头载了进去。\n$COM", me );
		me->unconcious();
		me->move( "/d/zuzhi/yipin_tang/dixia/laofang3" );
		return 0;
	}
	else if( random(2) )
	{
		message_vision("$CYN$N见势不妙，一个纵身向外飞退。。\n$COM", me );
		me->move( "/d/zuzhi/yipin_tang/yongdao3" );
		me->set_temp_marks("lnwm/yipin_tang/逃出",1);
		return 0;
	}
	else
	{
		message_vision("$CYN$N见势不妙，想向外飞逃，可门口已被堵住，翻板已在脚下打开，%N一个跟头栽了进去。\n$COM", me );
		me->unconcious();
		me->move( "/d/zuzhi/yipin_tang/dixia/laofang3" );
		return 0;
	}
}

int do_lingpai( string arg )
{
	object me, lingpai;
	string dir1,dir2;
	
	dir1 = dir_random();
	dir2 = to_english( dir1 );
	
	me = this_player();
	
	if( !me->IsMemberOf("yipin") )
		return notify_fail("你还没有加入一品堂。\n");
	
	if( !arg)
		return notify_fail("你可以向赫连云鹰申请玄武令(xuanwuling),\n玄阳令(xuanyangling)，玄云令(xuanyunling)和玄才令(xuancailing)。\n");
	
	if( arg == "玄武令" || arg == "xuanwuling" )
	{
		//xuanwuling 是 $YEL 的
		if( me->ZuzhiScore("yipin") <= 500 )
		{
			tell_object( me, "$CYN赫连云鹰微一沉吟你还是先为本堂多做些工作，然后再谈这件事。\n$COM" );
			return 1;
		}
		if( me->query("lnwm/yipin/领玄武令") < ( 4 << me->ZuzhiTouxianJibie("yipin") ) )
		{
			tell_object( me, "$YEL\n赫连云鹰点头道，这是在你现在这个职位上第" + (me->query("lnwm/yipin/领玄武令")+1) + "次申请玄武令。\n\n$COM",   );
			tell_object( me, "$CYN赫连云鹰转身拿起一块令牌，在上面写了几个字，然后郑重交给你。\n$COM" );
			tell_object( me, "$GRN\n赫连云鹰低声在你耳边说：玄武堂接引处，我们的暗号是--河图。\n$COM" );
			tell_object( me, "$GRN你在接引处说这两个字，自然有人接你上山。\n$COM" );
			me->add("lnwm/yipin/领玄武令", 1 );
			lingpai=new(__DIR__ "obj/xuanwuling");
			lingpai->set("持令人",me->query("id") );
			lingpai->move(me);
			return 1;
		}
		else
		{
			message_vision( "$RED\n赫连云鹰双眉一挑：你总上玄武堂做什么？你对本堂的贡献足够了么？？哼！\n\n$COM", me );
			return 1; 
		}
	}
	
	if( arg == "玄阳令" || arg == "xuanyangling" )
	{
		if ( ( me->query("mud_age") - me->query("lnwm/yipin/玄阳令")  ) < 600 )
		{
			tell_object( me, "赫连云鹰看了你一眼：你不是刚刚才从我这里拿走一块玄阳令么?\n");
			return 1;	   
		} 
		if ( me->query("lnwm/yipin	ask/领武器" ) )
		{
			lingpai=new(__DIR__ "obj/xuanyangling");
			lingpai->set("持令人",me->query("id") );
			lingpai->move(me);
			tell_object( me,"赫连云鹰低声对你说：在零一阁推"+dir1+"边的柱子就可进入地下。\n");
			me->set_temp("lnwm/enter_yipin/中",dir1);
			me->set_temp("lnwm/enter_yipin/英",dir2); 
			me->set("lnwm/yipin/玄阳令", me->query("mud_age") );
			return 1;
		}
		else
		{
			return notify_fail( "你目前没有申请这个的权利。\n");
		}
	}
	if( arg == "玄才令" || arg == "xuancailing" )
	{
		if ( (  me->query("mud_age") - me->query("lnwm/yipin/玄才令")  ) < 600 )
		{
			tell_object( me, "赫连云鹰看了你一眼：你不是刚刚才从我这里拿走一块玄才令么?\n" );
			return 1;	   
		}
		if ( me->query("lnwm/yipin	ask/领药" ) )
		{
			lingpai=new(__DIR__ "obj/xuancailing");
			lingpai->set("持令人",me->query("id") );
			lingpai->move(me);
			tell_object( me,"赫连云鹰低声对你说：在零一阁推"+dir1+"边的柱子就可进入地下。\n");
			me->set_temp("lnwm/enter_yipin/中",dir1);
			me->set_temp("lnwm/enter_yipin/英",dir2);	   
			me->set("lnwm/yipin/玄才令", me->query("mud_age") );					
			return 1;
		}
		else
		{
			return notify_fail( "你目前没有申请这个的权利。\n");
		}
	}
	if( arg == "玄云令" || arg == "xuanyunling" )
	{
		if ( ( me->query("mud_age") - me->query("lnwm/yipin/玄云令") ) < 600 )
		{
			tell_object( me, "赫连云鹰看了你一眼：你不是刚刚才从我这里拿走一块玄云令么?\n");
			return 1;	   
		}
		if ( me->query("lnwm/yipin	ask/领药" ) )
		{
			lingpai=new(__DIR__ "obj/xuanyunling");
			lingpai->set("持令人",me->query("id") );
			lingpai->move(me);
			tell_object( me,"赫连云鹰低声对你说：在零一阁推"+dir1+"边的柱子就可进入地下。\n");
			me->set_temp("lnwm/enter_yipin/中",dir1);
			me->set_temp("lnwm/enter_yipin/英",dir2);	 
			me->set("lnwm/yipin/玄云令", me->query("mud_age") );					
			return 1;
		}
		else
		{
			return notify_fail( "你目前没有申请这个的权利。\n");
		}
	}
	return notify_fail("你不能申请这个。\n");
}

string dir_random()
{
	string dir;
	int i;
	
	i = random(4);
	dir = "";
	
	switch( i )
	{
	case 0: dir = "东";break;
	case 1: dir = "西";break;
	case 2: dir = "南";break;
	case 3: dir = "北";break;
	}
	return dir;
}

string to_english( string arg )
{
	string dir;
	
	dir = "";
	if( arg == "东" ) dir = "east";
	if( arg == "西" ) dir = "west";
	if( arg == "南" ) dir = "south";
	if( arg == "北" ) dir = $COM"th";
	return dir;
}

int read_task( object me )
{
	string arg;
	int i;
	
	me = this_player();
	
	if( !me->IsMemberOf("yipin") ) return 0;
	
	//  if( arg = me->GetTaskMessage( "yipin" ) )
	if( me->query("yipin_task") )
	{
		tell_object( me, "$RED\n赫连云鹰冷笑了一声：连你的任务都不清楚！\n$COM" );
		tell_object( me, "$RED真是没用！\n$COM" );
		if ( me->ZuzhiScore("yipin") < -500000 )
			return 1;
		if ( me->ZuzhiScore("yipin") < 500 )	
		{
			me->AddZuzhiScore("yipin", -5 );
		}
		else
		{
			i = me->ZuzhiScore("yipin")/100;
			me->AddZuzhiScore("yipin", -i );	
		}
		tell_object( me , me->query("yipin_task	ask_message") );
		return 1;
	}	
	else
	{
		tell_object( me, "$RED\n赫连云鹰奇怪地看了你一眼：你怎么连自己有没有使命都搞不清楚？\n$COM" );
		me->AddZuzhiScore("yipin", -5 );
		tell_object( me , "\n你现在没有任务。\n" );
		return 1;
	}
}

int crash( object ob )
{
	destruct( ob );
}
*/
NPC_END;