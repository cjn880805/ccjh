//pub_sunchengxian.h 礼部侍郎孙承宪

NPC_BEGIN(CNpub_sunchengxian);

virtual void create()
{
	set_name("孙承宪","sun chenxian");

	set("icon", officer);
	set("title", "礼部侍郎");

	set("gender", "男性");
	set("age", 33);
	set("per",16);
	set("long","此人乃礼部侍郎，看起来颇有心计，善于钻营，两眼不时露出贪婪的神色。");
	set("no_huan",1);

};

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成");
	
	if(me->query("zhang/renwu5")==2 && !me->query("zhang/renwu5_ok") && !me->query_temp("zhang/renwu5_23"))
	{
		if (EQUALSTR(ob->querystr("id"), "coin") )
		{
			if(ob->query("value") >=500000 )
			{
				tell_object(me,"\n$HIC孙承宪打量四周，细看无人，赶紧接过递过来的银票揣在袖中。");
				tell_object(me,"$HIC但却面无表情的说道：“嗯，相爷的钱我就收下了，明日必定……”\n");
				if(me->query_temp("zhang/renwu5_230"))
				{
					me->delete_temp("zhang/renwu5_230");
					tell_object(me,"$HIC你冷笑几声：“看来孙大人不是不收礼，只是不收小礼罢了。”");
					tell_object(me,"$HIC孙承宪却毫无羞愧之色，反放声笑道：“哈哈哈……");
					tell_object(me,"$HIC不蛮您说，在下早有意投靠张相只是苦无门路罢了，在下是故意应和毛成龙，以一纸弹劾奏折换来张相的金银与主动拉拢。哈哈哈……”\n");
				}
				me->set_temp("zhang/renwu5_23",1);
				destruct(ob);
				if(me->query_temp("zhang/renwu5_21") && me->query_temp("zhang/renwu5_22")
					&& me->query_temp("zhang/renwu5_23") && me->query_temp("zhang/renwu5_24"))
				{
					me->set("zhang/renwu5_ok",2);
					me->delete_temp("zhang/renwu5_21");
					me->delete_temp("zhang/renwu5_22");
					me->delete_temp("zhang/renwu5_23");
					me->delete_temp("zhang/renwu5_24");
				}
				return 1;
			}
			else
			{
				tell_object(me,"\n$HIC孙承宪斜眼一瞥递过来的银票上的数目，冷笑道：“在下身为朝廷官员，自当尽心替皇上办事，是不会收取贿赂的。”\n");
				if(!me->query_temp("zhang/renwu5_230"))
					me->set_temp("zhang/renwu5_230",1);
			}
		}
	}
	return 0;
}
NPC_END;
