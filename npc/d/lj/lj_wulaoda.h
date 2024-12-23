//lj_wulaoda.h	武老大
//秦波 2002、6、5

NPC_BEGIN(CNlj_wulaoda);

void create()
{
	set_name("武老大","wulao da");
	set("long", "他虽然武功不太高，但确是条铁铮铮的汉子，恩怨分明，灵鹫宫属下三十六岛岛主、七十二洞洞主都以他为首领。");

	set("title", "灵鹫宫属下");
	set("gender", "男性");
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",young_man6);
	set("per", 10);
	set("str", 40);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set("no_kill",1);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

	set("combat_exp", 800000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hammer",100);
	set_skill("unarmed", 100);
	set_skill("yujiamu_quan", 100);
	set_skill("shenkong_xing",100);
	set_skill("xiaowuxiang", 100);
	set_skill("riyue_lun", 100);
  
	map_skill("force", "xiaowuxiang");
    map_skill("dodge", "shenkong_xing");
    map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "riyue_lun");
	map_skill("hammer", "riyue_lun");

	prepare_skill("unarmed", "yujiamu_quan");
	call_out(do_die, 1800);	
	set("no_kill",1);
};

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("lj/renwu6") ) 
	{
		CContainer * env = load_room("武陵春济楚谷");
		env->set("no_fight",1);
		env->set("no_move",1);
		me->set_temp("no_fei",1);
		tell_object(me, "\n$HIY你悄悄的进入了济楚谷，发现谷中聚集着很多奇形怪状的人。");
		tell_object(me, "$HIY其中一人看起来气宇不凡，正在对着众人说话，看情形似乎就是郁达夫口中所说的召集本次万仙大会的武老大。");
		tell_object(me, "$HIY你屏住呼吸，小心翼翼的躲在一旁倾听着他们谈话。");
		call_out(do_taolun, 2);	
	}
	else if(!me->query("lj/renwu7")) 
	{
		tell_object(me, "\n$HIY你悄悄的进入了济楚谷，发现谷中聚集着很多奇形怪状的人。");
		tell_object(me, "$HIY便在此时，左首高坡上有个声音飘了过来：“何方高人，到万仙大会来捣乱？当真将三十六洞洞主、七十二岛岛主，都不放在眼内吗？”");
		tell_object(me, "$HIY你权衡了一下，忍住好奇，掉头走了出去。");
		me->move(load_room("武陵春帘儿谷"));
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env;
	env = load_room("武陵春捻金峰");
	if(env->query("lj/wanxuanhuei"))
		tell_room(me->environment(), "\n$HIG万仙大会插血盟誓后，大伙杀上灵鹫宫夺取解药去呀！。\n");
	CContainer * env1=me->environment();
	if(env1->query("no_move"))
		env1->del("no_move");
	destruct(me);
}

static void do_taolun(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	switch(env->query("lj/taolun"))
	{
	case 0:
		tell_room(env, "\n$HIG武老大说道：今年三月初三，在下与天风洞安洞主、海马岛钦岛主等九人轮值供奉。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 1:
		tell_room(env, "$HIG采办了珍珠宝贝、绫罗绸缎、山珍海味、胭脂花粉等物，送到天山缥缈峰去……");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 2:
		tell_room(env, "$HIG我和安洞主、钦岛主等上缥缈峰之时，九个人心里都是怕得要命。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 3:
		tell_room(env, "$HIG老贼婆三年前嘱咐要齐备的药物，实在有几样太是难得，像三百年海龟的龟蛋，五尺长的鹿角，说什么也找不到。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 4:
		tell_room(env, "$HIG我们未能完全依照嘱咐备妥，料想这一次责罚必重。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 5:
		tell_room(env, "$HIG哪知道九个人战战兢兢的缴了物品，老贼婆派人传话出来。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 6:
		tell_room(env, "$HIG说道：“采购的物品也还罢了，九个孙子王八蛋，快快给我夹了尾巴，滚下峰去罢。”");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 7:
		tell_room(env, "$HIG我们便如遇到皇恩大赦，当真是大喜过望，立即下峰，都想早走一刻好一刻，别要老贼婆发觉物品不对，追究起来，这罪可就受得大了。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 8:
		tell_room(env, "$HIG九个人来到缥缈峰下，拉开蒙眼的黑布，只见山峰下死了三个人。其中一个，安洞主识得是西夏国一品堂中的高手，名叫九翼道人。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 9:
		tell_room(env, "$HIG九翼道人死于缥缈峰下，身上却有两处剑伤，大伙顿觉这事有些不对头。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 10:
		tell_room(env, "$HIR\n众人听到武老大说到这里，顿时一片哗然。\n ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 11:
		tell_room(env, "$HIG武老大接着说道：天山童姥不喜远行，常人又怎敢到缥缈峰百里之内去撒野？她自是极少有施展武功的时候。 ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 12:
		tell_room(env, "$HIG因此在缥缈峰百里之内，若要杀人，定是她亲自出手。 ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 13:
		tell_room(env, "$HIG我们素知她的脾气，有时故意引一两个高手到缥缈峰下，让这老太婆过过杀人的瘾头。 ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 14:
		tell_room(env, "$HIG她杀人向来一招便即取了性命，哪有在对手身上连下两招之理？ ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;	
	case 15:
		tell_room(env, "$HIR\n众人听到这里，不禁低头沉思，脸上深有忧色。\n ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 16:
		tell_room(env, "$HIG武老大继续说道：当时我一见九翼道人有两伤，心下起疑，再看另外两个死者，见到那两人亦非一招致命。 ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 17:
		tell_room(env, "$HIG我当下便和安、钦等诸位兄弟商议，这事可实在透着古怪。难道九翼道人等三人不是童姥所杀？");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 18:
		tell_room(env, "$HIG但如不是童姥下的手，灵鹫宫中童姥属下那些女人，又怎敢自行在缥缈峰下杀人，抢去了童姥一招杀人的乐趣？");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 19:
		tell_room(env, "$HIG九翼道人这等好手，杀起来其乐无穷，这般机缘等闲不易遇到，那比之抢去童姥到口的美食，尤为不敬。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 20:
		tell_room(env, "$HIG我们心中疑云重重，走出数里后，安洞主突然说道：“莫……莫非老夫人……生了……生了……””");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
	case 21:
		tell_room(env, "$HIR\n众人不约而同的都道：“生了病？”\n");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 22:
		tell_room(env, "$HIG武老大续道：大伙儿随即想起，人必有死，童姥姥本领再高，终究不是修炼成精，有金刚不坏之身。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 23:
		tell_room(env, "$HIG这一次我们供奉的物品不齐，她不加责罚，已是出奇，而九翼道人等死在峰下，身上居然不止一伤，更加启人疑窦。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 24:
		tell_room(env, "$HIG总而言之，其中一定有重大古怪。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
	case 25:
		tell_room(env, "$HIG当时众望所归，都盼安洞主出马探个究竟。安洞主自是义不容辞的自愿前去察看。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 26:
		tell_room(env, "$HIG武老大继续说道：我们在缥缈峰下苦苦等候，当真是度日如年，生怕安洞主有什么不测。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 27:
		tell_room(env, "$HIG直过了三个时辰，安洞主才回到约定的相会之所。我们见到他脸有喜色，大家先放下了心头大石。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 28:
		tell_room(env, "$HIG安洞主道：“老夫人有病，不在峰上。”");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 29:
		tell_room(env, "$HIG原来他悄悄重回缥缈峰，听到老贼婆的侍女们说话，得知老贼婆身患重病，出外采药求医去了！");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 30:
		tell_room(env, "$HIR\n武老大说到这里，人群中登时响起一片欢呼之声。\n天山童姥生病的讯息，他们当然早已得知，众人聚集在此，就是商议此事，但听武老大提及，仍然不禁喝彩。\n");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 31:
		tell_room(env, "$HIG武老大道：大家听到这个讯息，自是心花怒放，但又怕老贼婆诡计多端，故意装病来试探我们。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 32:
		tell_room(env, "$HIG九个人一商议，又过了两天，这才一齐再上缥缈峰窥探。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 33:
		tell_room(env, "$HIG这一次乌某人自己亲耳听到了，老贼婆果然是身患重病，半点也不假。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 34:
		tell_room(env, "$HIG说也惭愧，我们到灵鹫宫中去察看，谁也不敢放胆探听，大家竭力隐蔽，唯恐撞到了人。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 35:
		tell_room(env, "$HIG但在下在宫后花圃之中，还是给一个女童撞见了。这女娃儿似乎是个丫鬟之类，她突然抬头，我一个闪避不及，跟她打了个照面。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 36:
		tell_room(env, "$HIG在下深恐泄露了机密，纵上前去，施展擒拿法，便想将她抓住。那时我是甩出性命不要了。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 37:
		tell_room(env, "$HIG灵鹫宫中那些姑娘、太太们曾得老贼婆指点武功，个个非同小可。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 38:
		tell_room(env, "$HIG虽是个小小女童，只怕也十分了得。我这下冲上前去，自知是九死一生之举……");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 39:
		tell_room(env, "$HIR\n他声音微微发颤，显然当时局势凶险之极，此刻回思，犹有余悸。\n众人眼见他现下安然无恙，那么当日在缥缈峰上纵曾遇到什么危难，必也化险为夷。\n但想武老大居然敢在缥缈峰上动手，虽说是实逼处此，铤而走险，却也算得是胆大包天了。\n ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 40:
		tell_room(env, "$HIG只听武老大继续说道：哪知道……哪知道我左手一搭上这女娃儿肩头，右手抓住她的臂膀....");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 41:
		tell_room(env, "$HIG她竟毫不抗拒，身子一晃，便即软倒，全身没半点力气，却是一点武功也无。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 42:
		tell_room(env, "$HIG那时我大喜过望，一呆之下，两只脚酸软无比。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 43:
		tell_room(env, "$HIG不怕各位见笑，我是自己吓自己，这女娃儿软倒了，我这不成器的武老大，险些儿也软倒了。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 44:
		tell_room(env, "$HIR\n说到这里，人群中发出一阵笑声，各人心情为之一松。\n武老大虽讥嘲自己胆小，但人人均知他其实极是刚勇，敢到缥缈峰上出手拿人，岂是等闲之事？\n ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 45:
		tell_room(env, "$HIG武老大转头向众人朗声说道：老贼婆生了重病，那是千真万确的了。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 46:
		tell_room(env, "$HIG咱们要翻身脱难，只有鼓起勇气，拚命干上一场。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 47:
		tell_room(env, "$HIG不过老贼婆目前是否已回去缥缈峰灵鹫宫，咱们无法知晓。今后如何行止，要请大家合计合计。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 48:
		tell_room(env, "$HIR\n武老大一招手，他手下一人提了一只黑色布袋，走上前来，放在他身前。\n武老大解开袋口绳索，将袋口往下一捺，袋中露出一个人来。众人都是“啊”的一声，只见那人身形甚小，是个女童。\n");
		env->add("lj/taolun",1);
		me->call_out(do_tielao, 1);	
		me->call_out(do_taolun, 1);	
		break;
	case 49:
		tell_room(env, "$HIG武老大得意洋洋的道：这个女娃娃，便是乌某人从缥缈峰上擒下来的。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 50:
		tell_room(env, "$HIR\n众人齐声欢呼：“武老大了不起！”“当真是英雄好汉！”“三十六洞、七十二岛群仙，以你武老大居首！”\n众人欢呼声中，夹杂着一声声咿咿呀呀的哭泣，那女童双手按在脸上，呜呜而哭。\n");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 51:
		tell_room(env, "$HIG武老大大声道：众家兄弟，请大家取出兵刃，每人向这女娃娃砍上一刀，刺上一剑。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 52:
		tell_room(env, "$HIG这女娃娃年纪虽小，又是个哑巴，终究是缥缈峰的人物。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 53:
		tell_room(env, "$HIG大伙儿的刀头喝过了她身上的血，从此跟缥缈峰势不两立，就算再要有三心两意，那也不容你再畏缩后退了。");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 54:
		tell_room(env, "$HIR\n他一说完，当即擎鬼头刀在手。\n$HIG一干人等齐声叫道：“不错，该当如此！大伙儿歃血为盟，从此有进无退，跟老贼婆拚到底了。”");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 55:
		tell_room(env, "$$HIR\n\n\n武老大举起鬼头刀，叫道：“武老大第一个动手！”挥刀便向那身在布袋中的女童砍了下去。\n\n\n");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 56:
		tell_room(env, "$HIR你听得武老大言语，暗想道：“既然她是灵鹫宫门人，我怎能不救。”");
		env->add("lj/taolun",1);
		DTItemList * list = env->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		CChar * tielao;
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			tielao = (CChar *)obj;  
			if(EQUALSTR(tielao->querystr("name"), "女童"))
			{
				tielao->set_weight(10000);
				break;
			}
		}
		me->call_out(do_jiouren, 5);	
		break;
	}
}

static void do_jiouren(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * tielao;
	CChar * target;
	if(env->query("no_move"))
		env->del("no_move");
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		tielao = (CChar *)obj;  
		if(userp(tielao))
		{
			if(tielao->query("lj/renwu6"))
				target = (CChar *)obj;  
			continue;
		}
		if(EQUALSTR(tielao->querystr("name"), "女童"))
		{
			tell_room(env, "$HIR你的心猛然一惊，只见血花一溅，布袋中的女童“啊”的一声惨叫，缓缓的倒了下去。");
			env->set("lj/lost",1);
			env->del("no_fight");
			destruct(tielao);
			break;
		}
	}
	if(env->query("lj/lost"))
	{
		CChar * fighter = (CChar *)env->Present(param1);
		if(fighter)	
		{
			fighter->set("lj/renwu_lost",1);
			fighter->del("lj/renwu6");
			fighter->del("lj/renwu5");
			fighter->del("lj/renwu55");
			tell_room(env, "$HIR看着女童缓缓的倒下，你的心忽然间隐隐作痛，仿佛有种失去了亲人般的悲哀。");
		}
		me->call_out(do_die, 1);
	}
	else
	{
		tell_room(env, "$HIR众人齐声大喝：“什么人，胆敢来万仙大会捣乱，给我留下！”");
		env->set("lj/win",1);
		env->del("no_fight");

		target->add("combat_exp",5000);
		target->UpdateMe();
		tell_object(target, "\n\n$HIR你完成了“万仙大会勇救女童”的任务，获得了5000点的经验奖励。\n\n");
		target->set("lj/renwu7",1);
		target->del("lj/renwu6");
		target->del("lj/renwu5");
		
		((CUser *)me)->Ready_PK();
		((CUser *)target)->Ready_PK();
		target->kill_ob(me);	
		me->kill_ob(target);
	}
}

static void do_tielao(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	CNpc * tielao = load_npc("lj_tielao");
	tielao->set_name("女童","nv tong");
	tielao->set_weight(50000000);
	tielao->move(env);
}


NPC_END;




