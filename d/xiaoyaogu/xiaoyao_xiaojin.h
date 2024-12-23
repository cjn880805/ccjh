//xiaoyao_xiaojin.h 小径
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_xiaojin);

virtual void create()
{
	set_name( "小径");

	add_door("逍遥谷小溪边", "逍遥谷小溪边", "逍遥谷小径");
	add_door("逍遥谷小院", "逍遥谷小院", "逍遥谷小径");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_6") && !me->query("xy/renwu4_43") )
		{
			tell_object(me,"\n$YEL一只白色的蝴蝶忽悠悠地飞落在小径旁的花丛中。");
			tell_object(me,"$YEL李沧海蹑手蹑脚地掩了过去，双手做网状，待要扑住蝴蝶。");
			tell_object(me,"$YEL逍遥子从远处走来，看到李沧海，便发声问道：“小师妹，你在做什么呢？”");
			tell_object(me,"$YEL李沧海专心捕蝶，未查觉身后来人，闻声不由一惊，白蝴蝶“忽”地一声飞远了。");
			tell_object(me,"$YEL李沧海噘着小嘴，对逍遥子皱了皱鼻子道：“师兄好坏，吓走我的蝴蝶啦！”");
			tell_object(me,"$YEL逍遥子歉然：“哎呀，都怪我不好，小师妹别急，我这就去给你捉回来！”");

			tell_object(me,"$YEL说毕，逍遥子展开凌波微步，在花丛中追逐，只一会儿时间，宽大的袖拢中已关进了几只蝴蝶！");
			tell_object(me,"$YEL逍遥子摘了几束小径旁的狗尾草，结成一个小笼，将蝴蝶放了进去，然后递给了正迫不急待的李沧海。”");
			tell_object(me,"$YEL李沧海拿到关蝴蝶的小草笼，不由得欢呼起来：“师兄好厉害，蝴蝶翅膀一点也没破呢！”");

			me->set("xy/renwu4_43",1);
			me->add("xy/完成度",1);
		}
	}
}

XiaoYao_END;
