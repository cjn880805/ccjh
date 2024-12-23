NPC_BEGIN(CNwiz_newbie001);

void create()
{
	set_name("红龄", "Red age");

	set("title", "志愿者");
	set("icon", girl1);
	set("gender", "女性" );
	set("age", 25);
	
	set("combat_exp", 150);
	set("attitude", "friendly");	

	set("shuimm", 10);
	call_out(do_reset, 3600);
};

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->set("shuimm", 5);
}

void init(CChar * me)
{
	if(! userp(me) || me->query("level") > 1) return;

	call_out(do_greet, 2, me->object_id());
}

static void do_greet(CContainer * ob, LONG param1, LONG param2)
{
	CChar * who = (CChar *)(ob->environment())->Present(param1);
	if(! who) return;

	ob->say("你好！欢迎来到重出江湖的世界！请用鼠标左键点一下菜单。", who);
	ob->say("对，就是这样！鼠标左键表示翻页。有时NPC的话太长，会分成几页来显示。再继续点一下。", who);	
	ob->say("我是志愿者红龄，为新人提供服务。需要帮助的话请用鼠标右键点中我，将有菜单引导您进行操作。", who);	
	ob->say("这里有一份江湖上各大门派的拜师指南，也许对你有些帮助。", who);	
	CContainer * zhinan=load_item("jh_zhinan1");
	zhinan->move(who);
	ob->SendMenu(who);
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];

	if(strcmp(ask, "baohu") == 0)
	{
		if( me->query("kill/flee"))
		{
			say("你已经领过救命金丹了。", me);

			int left = me->query("kill/flee") - me->query("kill/death");
			if(left > 0)
				tell_object(me, snprintf(msg, 255, "$HIY目前你有%ld条命。", left));
			else
				tell_object(me, "$HIY你服下的救命金丹已经失效。");
		}
		else
		{
			say("江湖险恶，还是自己保重些吧。被人杀死后，不但辛苦赚得的经验技能损失很多，"
				"身上的装备，金钱也会被人抢走。所以，在人多的场景里尽量不要停留太长时间，"
				"最好设置逃跑系数，比如30。这样，当自身生命低于30%时就可自动逃跑。", me);
			say("我这里有三颗救命金丹，一旦遇到危险，可保你化险为夷。"
				"可也只能保佑你三次而已。所以，行走江湖，还是尽量靠自己。", me);
			say("我能帮你的也就这些了。在江湖行走，少不了朋友的帮助。多多结识一些江湖朋友，"
				"对你日后成长将有莫大好处。", me);

			me->set("kill/flee", 3);
			tell_object(me, "$HIY你服下三颗救命金丹，全身上下顿时金光发散。");
		}

		SendMenu(me);
		return 1;
	}

	if(me->query("mud_age") < 800)
	{
		if(! strlen(ask))
		{
			say("新来的，你好！需要帮助吗？", me);
			AddMenuItem("先教教我怎么操作吧。", "1", me);
			AddMenuItem("怎么赚钱", "z1", me);
			AddMenuItem("怎么练功", "l1", me);
			AddMenuItem("有什么工作安排我做吗？", "a1", me);
			AddMenuItem("能先给我点钱吗？", "b1", me);
			AddMenuItem("如何受到保护", "baohu", me);
		}		
		else if(strcmp(ask, "1") == 0)
		{
			say("这个游戏是全鼠标操作的。在场景里，可用鼠标左键选中目标。下面"
				"的目标按钮会告诉你当前目标的名称。如果这时菜单是被呼出状态，你"
				"就能够在菜单上找到针对该目标的全部操作了。", me);
			AddMenuItem("怎么呼出菜单呢？", "2", me);
			AddMenuItem("那怎么操作身上的东东呢。", "3", me);
		}
		else if(strcmp(ask, "2") == 0)
		{
			say("象刚才那样，在场景里轻击鼠标右键就能呼出菜单。", me);
			say("菜单被呼出后不会自动消失。为了不妨碍你的视线，可用鼠标右键关闭它。", me);
			AddMenuItem("那怎么操作身上的东东呢。", "3", me);
		}
		else if(strcmp(ask, "3") == 0)
		{
			say("一样的道理，用鼠标点携带物品就把当前目标换成你身上的物品了。"
				"和场景中的右键呼菜单的方式不同，需要双击列表框来呼出菜单。", me);
			AddMenuItem("这个简单，快告诉我怎么赚钱！", "z1", me);
		}
		else if(strcmp(ask, "z1") == 0)
		{
			say("别急。先看看右侧的列表框。你发现佛山北帝庙内有两尊佛像。", me);
			say("现在用鼠标选中财神爷，点观察，如果网慢的话要稍等会儿。然后"
				"，不错，就会出现关于佛像的描述。有些迷题呀就需要观察来解决。"
				"描述后会有磕头的提示。注意磕头会磕晕的哦！", me);
			say("每磕一次会得到一点钱。要注意自己的体力(HP)，快用尽时去找"
				"个地方睡觉，来恢复体力。", me);
			AddMenuItem("我可以去哪里睡觉呢。", "z2", me);
		}
		else if(strcmp(ask, "z2") == 0)
		{
			say("各个城市的客栈，各大门派的休息室，都可以睡觉。但并非所有的"
				"休息区都是安全的，经常会有一些坏人出没在那里，饲机偷你东西，"
				"或趁你睡觉的时候PK。要当心哦！", me);
			AddMenuItem("请问什么叫PK。", "z3", me);
			AddMenuItem("那离这里最近的客栈在哪里？", "z4", me);
		}
		else if(strcmp(ask, "z3") == 0)
		{
			say("所谓PK，就是玩家杀死玩家。死亡要掉经验和技能的，身上的装备啊"
				"钱啊也会掉的。所以要珍惜生命啊。", me);
			AddMenuItem("那离这里最近的客栈在哪里？", "z4", me);
		}
		else if(strcmp(ask, "z4") == 0)
		{
			say("出门后，找佛山英雄楼。二楼是可以休息的地方。", me);
			say("快一点的办法是把物品栏切换成出口列表，双击佛山英雄楼，就可以直接切场景了。", me);
			AddMenuItem("哦，那睡觉的指令。。。", "z5", me);
			AddMenuItem("明白了，那怎么练功。", "l1", me);
		}
		else if(strcmp(ask, "z5") == 0)
		{
			say("呵呵，当目标是自己时，有菜单指令的啊。", me);
			AddMenuItem("明白了，那怎么练功。", "l1", me);
		}
		else if(strcmp(ask, "l1") == 0)
		{
			say("先去熟悉一下地图吧。十五分钟后再来找我，我会教你一些行走江湖的法门。", me);
		}
		else if(strcmp(ask, "a1") == 0)
		{
			say("你的等级太低。先去泉州找水妹妹，问她要点事做吧。", me);
			AddMenuItem("不行，我找不到泉州！", "a2", me);
			AddMenuItem("哦，谢谢啦！", "", me);
		}
		else if(strcmp(ask, "a2") == 0)
		{
			say("去主页上下个地图吧。泉州离这里很近，出南门，走一会就到了。", me);			
		}
		else if(strcmp(ask, "b1") == 0)
		{
			if(! query("shuimm"))
			{
				say("真抱歉，有太多人求我帮忙了。实在不行你去给财神爷多磕几个响头，说不定他讨老人家一开心也会赏你几个零用钱呢。", me);
			}
			else
			{
				if(me->query_temp("newbie/shuimm"))
					say("我不是叫你去找水妹妹了吗，快去呀！！", me);
				else
				{
					add("shuimm", -1);

					CContainer * obj = load_item("sword_1");
					if(!obj->move(me))
						obj->move(me->environment());

					say(snprintf(msg, 255, "看你可怜兮兮的！那，我这有一把%s，去给泉州的水妹妹，就说是我让你找她的。她会给你一些帮助！", obj->name()), me);	
					me->set_temp("newbie/shuimm", obj->object_id());
				}
			}
		}
	}
	else if(me->query("level") < 5 && me->query("reward/exp") < 2)
	{
		//给奖励
		if(! me->query("reward/exp"))
		{
			say("怎么样，练功辛苦吧。", me);
			if(me->query("level") == 1)
			{
				if(me->query("combat_exp") > 100)
				{
					say("很努力呀！可是，为什么不升级呢。"
						"当你积累的经验超过斜线后的数字时，就可以升级了。"
						"可升级时，点自己的菜单里有升级选择。", me);
				}			
			}
			else
				say("不错，学会了升级。真的很用功啊。", me);
			
			me->add("combat_exp", 1000);
			tell_object(me, "$HIY你被系统奖励了1000点经验！");
			me->set("reward/exp", 1);
		}
		else
		{
			if(! me->querymap("family"))
				say("去找个师父拜吧，他会教你一些行走江湖的技能。", me);
			else if(! me->query_skill("literate", 1))
				say("怎么还不学习读书识字。读书识字高了增加智慧。智慧越高，"
					"学习起来越省经验。很重要哦。给襄阳学堂和扬州书院的先生学费，"
					"就可向他们请教！", me);
			else if(! me->query_skill("force", 1) )
				say("怎么还不学习基本内功。内功是武学之本，每个门派的技能只有"
					"配合本派内功才能发挥到极致。", me);
			else if(! me->query("max_mp"))
				say("现在你可以通过打坐来修炼内力(MP)了。学习了本派的高级内功后，"
					"准备高级内功到基本内功上。然后点自己，设置打坐系数。"
					"所谓打坐系数就是打坐时准备把多少点HP转化成MP。", me);
			else if(me->query("mks") < 50)
				say("江湖里主要靠杀NPC获得经验(即NK经验)。杀死50个NPC后再来找我。我会继续传授你一些江湖经验。", me);
			else
			{
				say("不错不错！你的进步很快！", me);
				me->add("combat_exp", 2000);
				me->set("reward/exp", 2);

				tell_object(me, "$HIY你被系统奖励了2000经验。");
			}
		}
	}
	else
	{
		if(! strlen(ask))
		{
			say("你想打听什么？", me);
			AddMenuItem("关于铸造兵器", "d1", me);
			AddMenuItem("关于购买房子", "d2", me);
			AddMenuItem("关于结婚", "d3", me);
			AddMenuItem("关于机器人", "d4", me);
			AddMenuItem("关于修改密码", "d5", me);
			AddMenuItem("关于睡觉和存盘", "d6", me);

			//
			//if(query("reward"))
			//	AddMenuItem("关于书的问题", "d7", me);
		}
		else if(strcmp(ask, "d1") == 0)
		{
			say("据说泉州有条狗藏有无数秘密。就是这条狗，居然会为江湖的人造兵刃。"
				"但你必须先为它找到它所需要的铁胚。自制兵刃会被打断。断掉的残骸"
				"一定要找回。你这一生就这么一件好武器，你一定要找到工艺最高明的"
				"工匠修复它。这个工匠在哪？想不到吧，居然是唐僧。他收费公道要5万。", me);
			say("当然，要年满16才能打造兵器。", me);					
		}
		else if(strcmp(ask, "d2") == 0)
		{
			say("人在江湖行走，时常想有个挡风遮雨的地方，不需要太大。好吧，"
				"开始攒钱。当你拥有了50万，就可买一套属于自己的小房间了。如果"
				"有了100万，那么还是买个两人居吧，为你将来的老婆孩子做准备。"
				"一但买了某个城市的住房，就自动入了该城的户籍。", me);
			say("江湖中各大城市均有现房供售。数量有限，售完为止。好多玩家"
				"喜欢往家里拣东西。外人又闯不进来。于是个个成了古董收藏爱好者，"
				"家里藏满了盆盆罐罐，甚至连乞丐都懒得拣的垃圾。", me);
			say("一些豪门贵族家中还拳养了仆人。可以给你的仆人起个中意的名字，"
				"比如旺财，小翠之类。教会他如何对待客人和主人。见了客人要问好，"
				"见了主人要行礼。", me);
		}
		else if(strcmp(ask, "d3") == 0)
		{
			say("仗剑携得美人归，多少江湖人士的梦想。男18女16，就可双双到红娘庄"
				"办理结婚手续了。50万给红娘，得同心印一块。男方先把手按在同心印"
				"上指天发誓，表示愿与女方白头相老，不离不弃；接着女方也把手按在"
				"同心印上发誓，就算成了。", me);
			say("然后再50万给空白妖女，宴请全体在线玩家。接着就可带老婆回家洞房了。", me);
			say("邀请别人来自己的家，用指令invite，被邀请的人用指令accept接受。"
				"邀请不能急，主人要显得有诚意，一个个的来。 ", me);
			say("老公老婆可以相互查看对方武功，指点武功。以后有宝宝了，上线后到自己的房间里让女方查找宝宝位置。", me);
		}
		else if(strcmp(ask, "d4") == 0)
		{
			say("纸符人:读书机器人\n纸咒人:练习机器人\n纸偶人:打坐机器人", me);
			say("使用机器人必须找一处可以练功又可以睡觉的所在。通常是大理下人"
				"居.不过因为那里练功的新人比较的多,经常有坏人出没此处,窃人钱财"
				"或者PK.要小心。", me);
			say("其实又能打坐又能睡觉的地方很多,好象峨嵋就有几处.当你16岁可以"
				"买房子了，在家里练功才是最安全的。或者有朋友什么的,借朋友的家"
				"一用,挂人练功也是不错的主意.", me);
			say("实在不行就花钱,找有玩家开的书店,进里面租书读,在那里练功应该也是安全的。", me);
			say("再不行看看哪个玩家帮派门槛低,肯收留你,到他们总部去读书练功,也可以!", me);
			say("上述地方,就可以使用纸人了。其他地方使用纸人,纸人根本点不起来,就熄灭了。", me);
			say("当纸人工作时,还会要求你做一些设置.比如读书,就要选择要读的书."
				"练习就要选择练习的高级.打坐,要先设置好打坐系数", me);
		}
		else if(strcmp(ask, "d5") == 0)
		{
			say("如果不喜欢注册时设定的密码，可在线修改自己的密码。 ", me);
			say("修改密码的指令是/password 旧密码。当系统提示通过时，再用"
				"一次/password 新密码。", me);
			say("注意新密码不能超过10个字符，中间不要有空格。否则，登陆不进去哦。", me);
		}
		else if(strcmp(ask, "d6") == 0)
		{
			say("恢复HP和MP一个很有效的办法就是睡觉，又省钱又省力。可以到各城市"
				"的客栈或各门派的休息室睡觉。不过要提醒您的是，有些睡觉的地方不"
				"限制战斗。被人趁你熟睡的时候砍死，我可不负责哦。", me);
			say("另外，很多客栈同时也是存盘点。意思就是说，在此存盘后，你的起始"
				"地点就被设置成这里了。以后不论用回城卷轴，还是下次连线进入，还"
				"是被砍死，都会回到这里。", me);
			say("至于睡觉的地点和存盘点，论坛精华区也都资料。去查查吧。", me);
			say("特别说明一点，家也是可利用的存盘点。以后买了属于自己的家，在家"
				"睡觉练功就安全多了。", me);
		}
		else
			return 0;
		SendMenu(me);
		return 1;
	}		

	return CNpc::do_talk(me,ask);
}

NPC_END;