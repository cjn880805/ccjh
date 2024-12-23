//chunjie_hb.h 压岁红包
//muri 2002-2-5

ITEM_BEGIN(CIchunjie_hb)

void create(int nFlag = 0)	
{
	set_name("压岁红包", "hong bao");
	set_weight(10);
    set("no_give", "好大方的人呀，不如给我吧！");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","这么珍贵的东西你也扔？！");

	set("long", "这是金智塔公司赠送给新年钟声敲响时，仍然在线奋斗的朋友们的压岁红包。");
	set("unit", "个");	

	set("open_msg", "小心翼翼的撕开了红包封口");
}

int Can_Use()
{
	return 1;
}
 
int do_use(CChar * me, CContainer * who)
{
	if(querystr("owner")[0])
	{
		char msg[255];
		int number;
		if(!query("number"))
		{
			if(random(2))
			{
				number=random(1001)+1000;
				if(me->query("level")>10)
				{
					message_vision(snprintf(msg, 255, "\n$HIY$N%s，从红包中倒出了一堆的金币，美滋滋的数了起来...", querystr("open_msg")), me);
					tell_object(me,snprintf(msg, 255, "1个金币、2个金币、3个金币、4个金币......") );
					tell_object(me,snprintf(msg, 255, "108个金币、208个金币、308个金币、408个金币......"));
					tell_object(me,snprintf(msg, 255, "%d个金币、%d个金币、%d个金币、%d个金币......",number-500-random(100),number-300-random(100),number-100-random(100),number));
					tell_object(me,snprintf(msg, 255, "$HIY你终于数完了面前的这堆金币，满意的点了点头，总共收到了%d个金币的一个红包。\n",number));
				}
				else
				{
					number=1;
					message_vision(snprintf(msg, 255, "\n$HIY$N%s，从红包中倒出了一堆的金币，美滋滋的数了起来...", querystr("open_msg")), me);
					tell_object(me,snprintf(msg, 255, "1个金币、1个金币、1个金币、还是只有1个金币。。") );
					tell_object(me,snprintf(msg, 255, "$HIY你傻瞪瞪的看着这个只包了1枚金币的红包，不由一阵感慨：做大米真好！\n",number));
				}
				CMoney::Pay_Player(me, number);
			}
			else
			{
				if(me->query("level")>10)
					number=random(61)+60;
				else
					number=1;
				me->add("combat_exp",number);
				me->UpdateMe();
				tell_object(me,snprintf(msg, 255, "\n$HIY你%s，发现里面竟是一本讲解行走江湖的经验之大全。你从中领悟了%d点的江湖经验。\n", querystr("open_msg"),number));
			}
		}
		else
		{
			if(me->query("level")>10)
				number=(random(101)+60)*query("number");
			else
				number=1;
			me->add("combat_exp",number);
			me->UpdateMe();
			message_vision(snprintf(msg, 255, "\n$HIY$N%s，发现里面竟是一本讲解行走江湖的经验之大全。$N阅读之后，从中领悟了%d点的江湖经验。\n", querystr("open_msg"),number), me);
		}
	}
	destruct(this);
	return 1;

}

void owner_is_killed(CChar * me)
{
	destruct(this);
}

ITEM_END;




