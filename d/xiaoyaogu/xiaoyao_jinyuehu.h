//xiaoyao_jinyuehu.h 镜月湖
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_jinyuehu);

virtual void create()
{
	set_name( "镜月湖");

	add_door("逍遥谷小溪边", "逍遥谷小溪边", "逍遥谷镜月湖");
	add_door("逍遥谷瀑布", "逍遥谷瀑布", "逍遥谷镜月湖");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu7_2") && me->query("xy/renwu7_3")==2 &&!me->query("xy/renwu7_33")	&& !me->query("xy/renwu8"))
		{
			tell_object(me,"\n$HIC逍遥子一遍一遍地拾起石子，扔进镜月湖中，一付神不守舍的样子。");
			tell_object(me,"$HIC不远处，一群长相俊美的男子拥着李秋痕，缓缓向这边走了过来。\n");
			tell_object(me,"\n$HIC欧阳公子一边行，一边目不转睛地盯着李秋痕，讨好地说道：\n");
			tell_object(me,"$HIC“这位姑娘莫非是从天下掉下来的仙女。得遇如此貌若天仙的美女，小可真是三生有幸呀！”");
			tell_object(me,"$HIC李秋痕吃吃地笑道：“这位公子可真会说话，妾身听了，心里可是欢喜得紧呢！”\n");
			tell_object(me,"\n$HIC欧阳公子捧起李秋痕的脸，给了她一个无限温柔的吻。");
			tell_object(me,"$HIC李秋痕嘻嘻地笑了起来。");
			tell_object(me,"$HIC一旁的花花公子不甘示弱，从身后拿出一把艳丽的鲜花送给李秋痕，随便在她脸上轻轻捏了一把。\n");
			tell_object(me,"\n$HIC见此情景，逍遥子勃然大怒，他狠狠甩了李秋痕一记耳光，转头愤然离去。\n");
			me->add("xy/完成度",1);
			me->set("xy/renwu7_33",1);//逍遥谷镜月湖剧情:逍遥子负气离去
		}
	}
}

XiaoYao_END;
