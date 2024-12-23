//pub_lancaihe.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_lancaihe);

void create()
{
	set_name("蓝采和", "lan cai he");
	
	set("title", "八洞神仙");
	set("long","他破衣蓝衫，腰系三寸墨水腰带，一脚着靴，一脚赤足，手持二尺余长的大拍板。");
	
	set("icon", young_man6);
	set("per",32);
	
	set("gender", "男性");
	set("level", 300);
	set("age", 1000);
	set("no_huan",1);
	
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(me->query_temp("yuandna/lan_liwu") )
	{
		if(! strlen(ask))
		{
			say(snprintf(msg, 255,"蓝采和对你笑道：“这位%s，是否原听本仙踏歌一曲？”",query_respect(me)),me);
			AddMenuItem("愿意","yes",me);
			AddMenuItem("不愿意","",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "yes") )
		{
			tell_object(me,"\n$HIC采和乃出庭前，扣衣盘舞，俯仰纡徐，仍执云阳之板，颠狂跳跃。大踏步歌曰：\n");
			int index=random(12)+1;
			int exp;
			me->delete_temp("yuandna/lan_liwu");
			switch(index)
			{
			case 1:
				tell_object(me,"$HIC时人想云路，云路杳无踪；");
				tell_object(me,"$HIC高山多险峻，涧涧有真龙。");
				tell_object(me,"$HIC碧草前兼后，白云西复东；");
				tell_object(me,"$HIC欲知云路近，云路在虚空。\n");
				if(!me->query("yuandna/lan/1"))
				{
					me->set("yuandna/lan/1",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 2:
				tell_object(me,"$HIC我见世间人，生而还复死；");
				tell_object(me,"$HIC昨朝犹二八，壮气胸襟土。");
				tell_object(me,"$HIC如今七十过，困苦形憔悴；");
				tell_object(me,"$HIC恰似春回花，朝开暮落矣。\n");
				if(!me->query("yuandna/lan/2"))
				{
					me->set("yuandna/lan/2",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 3:
				tell_object(me,"$HIC白鹤那肯化，千里作一息；");
				tell_object(me,"$HIC欲往蓬莱山，将此无粮食。");
				tell_object(me,"$HIC未达毛羽落，离群心惨恻；");
				tell_object(me,"$HIC却归旧来巢，妻子不相识。\n");
				if(!me->query("yuandna/lan/3"))
				{
					me->set("yuandna/lan/3",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 4:
				tell_object(me,"$HIC垂柳暗如烟，飞花飘似雪；");
				tell_object(me,"$HIC夫居离妇州，妇在思夫县。");
				tell_object(me,"$HIC各在天一涯，何时复相见？");
				tell_object(me,"$HIC寄语明月楼，莫栖观飞燕。\n");
				if(!me->query("yuandna/lan/4"))
				{
					me->set("yuandna/lan/4",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 5:
				tell_object(me,"$HIC骝马珊瑚鞭，驱驰荡荡道；");
				tell_object(me,"$HIC自怜美少年，不信有衰老。");
				tell_object(me,"$HIC白发应会生，红颜岂长保；");
				tell_object(me,"$HIC但看见邱山，介是蓬莱岛。\n");
				if(!me->query("yuandna/lan/5"))
				{
					me->set("yuandna/lan/5",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 6:
				tell_object(me,"$HIC本志慕道伦，道伦常护亲；");
				tell_object(me,"$HIC时逢桃源客，每接话神宾。");
				tell_object(me,"$HIC谈玄明月夜，穷理日临晨；");
				tell_object(me,"$HIC万机但泯迹，方识本来人。\n");
				if(!me->query("yuandna/lan/6"))
				{
					me->set("yuandna/lan/6",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 7:
				tell_object(me,"$HIC铁笔大纵横，身材极魁梧；");
				tell_object(me,"$HIC生为有胆身，死作无名鬼。");
				tell_object(me,"$HIC自古如此多，君今争奈何？");
				tell_object(me,"$HIC可来白云里，教你紫芝歌。\n");
				if(!me->query("yuandna/lan/7"))
				{
					me->set("yuandna/lan/7",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 8:
				tell_object(me,"$HIC浩浩黄河水，东流长不息；");
				tell_object(me,"$HIC悠悠不见清，人人寿有极。");
				tell_object(me,"$HIC我俗乘白云，曷由我生翼；");
				tell_object(me,"$HIC唯当少壮时，行住须努力。\n");
				if(!me->query("yuandna/lan/8"))
				{
					me->set("yuandna/lan/8",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 9:
				tell_object(me,"$HIC我今有一襦，非罗复非绮；");
				tell_object(me,"$HIC借问作何色？不红亦不紫。");
				tell_object(me,"$HIC夏天将作衫，冬天将作被，");
				tell_object(me,"$HIC冬夏递互用，长年只如是。\n");
				if(!me->query("yuandna/lan/9"))
				{
					me->set("yuandna/lan/9",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 10:
				tell_object(me,"$HIC世事何悠悠，贪心未肯休；");
				tell_object(me,"$HIC听尽天地名，何时得歇头？");
				tell_object(me,"$HIC四时凋变易，八节急如流；");
				tell_object(me,"$HIC为报大宅主，云地骑白牛。\n");
				if(!me->query("yuandna/lan/10"))
				{
					me->set("yuandna/lan/10",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 11:
				tell_object(me,"$HIC高高山顶上，四顿极无极；");
				tell_object(me,"$HIC独坐无人知，孤月寒照泉。");
				tell_object(me,"$HIC泉中且无月，月自在青天；");
				tell_object(me,"$HIC吟此一曲歌，歌中本是仙。\n");
				if(!me->query("yuandna/lan/11"))
				{
					me->set("yuandna/lan/11",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			case 12:
				tell_object(me,"$HIC东家一老婆，富来三五年；");
				tell_object(me,"$HIC昔日贫于我，今笑我无钱。");
				tell_object(me,"$HIC渠笑我在后，戏笑渠在前；");
				tell_object(me,"$HIC相笑倘不止，东边复西边。\n");
				if(!me->query("yuandna/lan/12"))
				{
					me->set("yuandna/lan/12",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL听蓝采和踏歌，你感悟人生，受益菲浅。");
						tell_object(me,snprintf(msg, 255,"$YEL你的经验上升了%d点。\n",exp));
					}
				}
				break;
			}
		}
	}
	else
	{
		say("蓝采和嘿嘿笑道：“节日快乐！”",me);
		if(!me->query("yuandna/lan1") && !me->query_temp("yuandna/play") )
		{
			if(! strlen(ask) && DIFFERSTR(me->querystr("gender"), "女性"))
			{
				say(snprintf(msg, 255,"蓝采和嘿嘿笑道：“本仙素喜与人比试谁更不怕冷，%s可欲一试？”",query_respect(me)),me);
				AddMenuItem("愿意","yes",me);
				AddMenuItem("不愿意","",me);
			}
			else if(!strcmp(ask, "yes") )
			{
				do_play(me);
			}
		}
		SendMenu(me);
	}
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "玉片") && ob->Query_Amount() >=1
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/lan_liwu") )
	{
		char msg[255];
		destruct(ob);
		if(me->query("yuandna/lan/count")>8)
		{
			me->set("yuandna/lan_liwu",1);
			me->del("yuandna/lan");
			tell_object(me,snprintf(msg, 255,"\n$HIC蓝采和笑道：“%s真乃知音，本仙有一薄礼相赠！”",query_respect(me)));
			load_item("redqin")->move(me);
		}
		else
		{
			me->set_temp("yuandna/lan_liwu",1);
			tell_object(me,"\n$HIC蓝采和对你笑道：“否原听本仙踏歌一曲？”");
		}
		return 1;
	}
	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n向$N看了看，呵呵一笑，“自从渡过东海之后，近千年来我早已不再与人动手了。”", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

void do_play(CChar * me)
{
	tell_object(me,"\n$HIR蓝采和精赤上身，飞立于「红浪阁」顶，任凭风雨及体。");
	tell_object(me,"$HIR你脱下上衣，也站了上去。\n");
	me->set_temp("yuandna/play",1);
	me->call_out(do_game, 5);
	
}

static void do_game(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	
	if(EQUALSTR((me->environment())->querystr("base_name"),"武陵春红浪阁" ))
	{
		char msg[255];
		if(random(3))
		{
			if(random(2))
				tell_object(me,"\n$HIR一阵寒风吹来你情不自禁的打了个冷颤，你忙运起内功抵抗，还是如置身在冰川之中，你摇摇欲坠。\n");
			else
			{
				tell_object(me,"\n$HIR雨点打在你身上跟刀子刮似的，你渐渐的支持不住了。");
				tell_object(me,"$HIR但看到边上的蓝采合那满不在乎的神情，你升起了一股傲意，强迫自己苦苦支撑下去。\n");
			}
			me->add_temp("yuandna/lan1",1);
			me->call_out(do_game, 5);
		}
		else
		{
			tell_object(me,"$HIR寒风吹得你瑟瑟发抖，你终于坚持不住，一个跟斗栽了下来，只冻得面色苍白，半晌无声。");

			if(me->query("con")>=20)
			{
				tell_object(me,"$HIR蓝采和扮了个鬼脸：“还好还好！”\n");
				int exp=random(500)+500+me->query_temp("yuandna/lan1")*100;
				me->add("combat_exp",exp);
				me->UpdateMe();
				tell_object(me,snprintf(msg,255,"$YEL你获得了蓝采和的赏识，经验上升了%d点。\n",exp));
			}
			if(me->query_temp("yuandna/lan1"))
				me->delete_temp("yuandna/lan1");
			me->set("yuandna/lan1",1);
			me->delete_temp("yuandna/play");
		}
	}
	else
	{
		if(me->query_temp("yuandna/lan1"))
			me->delete_temp("yuandna/lan1");
		me->delete_temp("yuandna/play");
	}
}
NPC_END;
