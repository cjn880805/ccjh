//huashan_pbhoushandong.h 华山瀑布后山洞

ROOM_BEGIN(CRHuaShan_pbhoushandong);

virtual void create()			//Call it when Room Create
{
	set_name( "华山瀑布后山洞");
	add_door("华山山洪瀑布", "华山山洪瀑布", "华山瀑布后山洞");
	add_npc("was_shuangmu");
	
	set("long", "洞内原来别有洞天，借着洞外微弱的光，你只见一人正在练剑。");  
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query_temp("was/renwu1_1") && !me->query_temp("was/renwu1_2"))
		{
			me->set_temp("was/renwu1_2",1);//遇上双木师兄(华山派)
			tell_object(me,"\n$HIC洞内原来别有洞天，借着洞外微弱的光，你只见一人正在练剑。");
			tell_object(me,"$HIC但见此人手持木剑随意虚劈点刺，单从其剑式，你无法估计他的功力，因为根本没有招式，但无可否认，他用的是剑法。\n");
			tell_object(me,"$HIC你渐渐适应洞内昏暗，不其然望向眼前人的面孔，惊觉此人原来是失踪多年的双木师兄……\n");
		}
	}
}

ROOM_END;
