// Richard Hähne 2019

using UnrealBuildTool;
using System.Collections.Generic;

public class ue4_gas_predictionEditorTarget : TargetRules
{
	public ue4_gas_predictionEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "ue4_gas_prediction" } );
	}
}
