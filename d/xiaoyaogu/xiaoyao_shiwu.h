//xiaoyao_shiwu.h 石屋
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_shiwu1);

virtual void create()
{
	set_name( "石屋");

	set("no_get",1);
	set("no_fight",1);
	set("no_cast",1);
	add_npc("xy_xiaoyaozi");

	add_door("逍遥谷练功场", "逍遥谷练功场", "逍遥谷石屋");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu7_2") )
		{
			CContainer * env=me->environment();
			CContainer * XyNpc=env->present("xiaoyao zi");
			if(XyNpc)
				destruct(XyNpc);
		}
		else if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_6") && !me->query("xy/renwu4_42") )
		{
			tell_object(me,"\n$YEL天山铁姥比了一招天山六阳掌的招式，疑惑地问逍遥子：“师弟，你替我看看，师父所授的这一式「阳关三叠」，我始终无法融会贯通，你可知是什么原因吗？”");
			tell_object(me,"$YEL逍遥子皱着眉头思索了一会儿，拉起天山铁姥的手比划了一下：“似乎应该这样才更合适…”");
			tell_object(me,"$YEL正待详说，门外闯进了满脸笑容的李秋痕。");
			tell_object(me,"$YEL李秋痕拉住逍遥子的手说道：“师哥，我今日从无量山中的一个采茶女处学会的一段曲子，很有意思，你来我唱给你听！”");
			tell_object(me,"$YEL说毕，拉了逍遥子的手便走。");
			tell_object(me,"\n$YEL天山铁姥只恨得银牙紧咬，重重地哼了一声。\n");

			me->set("xy/renwu4_42",1);
			me->add("xy/完成度",1);
		}
	}
}

XiaoYao_END;
